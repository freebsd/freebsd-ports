- Add FreeBSD-specific includes for PTY support (libutil.h, ttycom.h, ioctl.h)
- Add missing Boost deadline_timer header
- Restrict prctl(PR_SET_PDEATHSIG) to Linux only (not available on FreeBSD)

--- src/cpp/core/system/PosixChildProcess.cpp.orig	2025-11-30 07:45:37 UTC
+++ src/cpp/core/system/PosixChildProcess.cpp
@@ -24,6 +24,10 @@
 #include <util.h>
 #include <sys/ttycom.h>
 #include <sys/ioctl.h>
+#elif defined(__FreeBSD__)
+#include <libutil.h>
+#include <sys/ttycom.h>
+#include <sys/ioctl.h>
 #elif defined(__linux__)
 #include <pty.h>
 #include <asm/ioctls.h>
@@ -34,6 +38,7 @@
 #include <sys/types.h>
 
 #include <boost/asio.hpp>
+#include <boost/asio/deadline_timer.hpp>
 #include <boost/bind/bind.hpp>
 
 #include <shared_core/Error.hpp>
@@ -814,7 +819,7 @@ Error ChildProcess::run()
 
       if (options_.exitWithParent)
       {
-#ifndef __APPLE__
+#ifdef __linux__
          // set a bit indicating we want to die when our parent dies
          if (::prctl(PR_SET_PDEATHSIG, SIGTERM) == -1)
             LOG_ERROR(systemError(errno, ERROR_LOCATION));
