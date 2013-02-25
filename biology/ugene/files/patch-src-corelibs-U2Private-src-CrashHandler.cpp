--- ./src/corelibs/U2Private/src/CrashHandler.cpp.orig	2012-10-30 15:36:22.000000000 +0100
+++ ./src/corelibs/U2Private/src/CrashHandler.cpp	2012-10-30 15:47:47.000000000 +0100
@@ -253,7 +253,7 @@
     }
     //handler = AddVectoredExceptionHandler(1, CrashHandlerFunc);
     
-#elif defined( Q_OS_MAC)
+#elif defined( Q_OS_MAC ) || defined ( Q_OS_FREEBSD )
     return; //TODO: implement crash hander for MAC OS
 #else
     stack_t sigstk;
@@ -284,7 +284,7 @@
 void CrashHandler::runMonitorProcess(const QString &exceptionType) {
     QString path = QCoreApplication::applicationDirPath() + "/ugenem";
 
-#ifndef Q_OS_WIN
+#if !defined ( Q_OS_WIN ) && !defined ( Q_OS_FREEBSD )
     char pid_buf[30];
     sprintf(pid_buf, "%d", getpid());
     char name_buf[512];
