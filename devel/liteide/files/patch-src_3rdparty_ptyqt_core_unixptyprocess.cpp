--- src/3rdparty/ptyqt/core/unixptyprocess.cpp.orig	2020-04-24 15:02:10 UTC
+++ src/3rdparty/ptyqt/core/unixptyprocess.cpp
@@ -11,6 +11,7 @@
 #include <QFileInfo>
 #include <QCoreApplication>
 #include <signal.h>
+#include <sys/time.h>
 
 /* for pty_getproc */
 #if defined(__linux__)
@@ -416,7 +417,6 @@ void ShellProcess::setupChildProcess()
     utmpxInfo.ut_type = USER_PROCESS;
     utmpxInfo.ut_pid = getpid();
 
-    utmpxname(_PATH_UTMPX);
     setutxent();
     pututxline(&utmpxInfo);
     endutxent();
