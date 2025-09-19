--- src/3rdparty/ptyqt/core/unixptyprocess.cpp.orig	2025-05-19 13:29:36 UTC
+++ src/3rdparty/ptyqt/core/unixptyprocess.cpp
@@ -13,6 +13,7 @@
 #include <QFileInfo>
 #include <QCoreApplication>
 #include <signal.h>
+#include <sys/time.h>
 
 /* for pty_getproc */
 #if defined(__linux__)
@@ -462,7 +463,6 @@ void ShellProcess::setupChildProcess()
     utmpxInfo.ut_type = USER_PROCESS;
     utmpxInfo.ut_pid = getpid();
 
-    utmpxname(_PATH_UTMPX);
     setutxent();
     pututxline(&utmpxInfo);
     endutxent();
