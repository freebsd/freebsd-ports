--- src/cpp/core/system/PosixChildProcess.cpp.orig	2022-12-30 20:28:33 UTC
+++ src/cpp/core/system/PosixChildProcess.cpp
@@ -28,6 +28,11 @@
 #include <pty.h>
 #include <asm/ioctls.h>
 #include <sys/prctl.h>
+#elif defined(__FreeBSD__) // for forkpty
+#include <sys/types.h>
+#include <sys/ioctl.h>
+#include <termios.h>
+#include <libutil.h>
 #endif
 
 #include <sys/wait.h>
@@ -807,7 +812,7 @@ Error ChildProcess::run()
 
       if (options_.exitWithParent)
       {
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
          // set a bit indicating we want to die when our parent dies
          if (::prctl(PR_SET_PDEATHSIG, SIGTERM) == -1)
             LOG_ERROR(systemError(errno, ERROR_LOCATION));
