#ifndef QT_UPDATE_CHECKER_H
#define QT_UPDATE_CHECKER_H

#include "qt/utility/QtThreadedFunctor.h"
#include "UpdateChecker.h"

class QtUpdateChecker
	: public UpdateChecker
{
public:
	struct Result
	{
		bool success = false;
		QString url;
	};

	static bool needsAutomaticCheck();
	static void check(bool force, std::function<void(Result)> callback);

	virtual void checkUpdate() override;

private:
	QtThreadedLambdaFunctor m_onQtThread;
};

#endif // QT_UPDATE_CHECKER_H
