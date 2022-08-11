--- src/cpp/core/system/PosixChildProcess.cpp.orig	2022-07-06 19:59:49 UTC
+++ src/cpp/core/system/PosixChildProcess.cpp
@@ -25,9 +25,12 @@
 #include <sys/ttycom.h>
 #include <sys/ioctl.h>
 #else
-#include <pty.h>
-#include <asm/ioctls.h>
-#include <sys/prctl.h>
+//#include <pty.h>
+//#include <asm/ioctls.h>
+//#include <sys/prctl.h>
+#include <sys/tty.h>
+#include <sys/ttycom.h>
+#include <libutil.h>
 #endif
 
 #include <sys/wait.h>
@@ -807,7 +810,7 @@ Error ChildProcess::run()
 
       if (options_.exitWithParent)
       {
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
          // set a bit indicating we want to die when our parent dies
          if (::prctl(PR_SET_PDEATHSIG, SIGTERM) == -1)
             LOG_ERROR(systemError(errno, ERROR_LOCATION));
