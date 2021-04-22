--- rts/System/Platform/Linux/ThreadSupport.cpp.orig	2021-01-01 16:12:22 UTC
+++ rts/System/Platform/Linux/ThreadSupport.cpp
@@ -7,6 +7,7 @@
 #include <csignal>
 #include <fstream>
 #include <sys/syscall.h>
+#include <pthread_np.h>
 
 #include "System/Log/ILog.h"
 #include "System/Platform/Threading.h"
@@ -42,7 +43,7 @@ enum LinuxThreadState {
  * There is no glibc wrapper for this system call, so you have to write one:
  */
 static int gettid() {
-	return syscall(SYS_gettid);
+	return pthread_getthreadid_np();
 }
 
 /**
