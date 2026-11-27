--- dlls/win32u/vulkan.c.orig	2026-11-19 14:08:52 UTC
+++ dlls/win32u/vulkan.c
@@ -30,6 +30,10 @@
 #include <unistd.h>
 #include <assert.h>
 
+#if defined(__FreeBSD__)
+#include <sys/thr.h>
+#endif
+
 #include "ntstatus.h"
 #define WIN32_NO_STATUS
 #include "win32u_private.h"
@@ -646,7 +650,14 @@ static void *signaller_worker( void *arg )
 
 static void *signaller_worker( void *arg )
 {
+#if defined(__FreeBSD__)
+    // From server.c get_unix_tid function
+    long lwpid;
+    thr_self(&lwpid);
+    int unix_tid = lwpid;
+#else
     int unix_tid = gettid();
+#endif
     struct vulkan_device *device = arg;
     struct semaphore *sem;
     VkSemaphoreWaitInfo wait_info = { 0 };
