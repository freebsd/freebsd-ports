--- dlls/winevulkan/vulkan.c.orig
+++ dlls/winevulkan/vulkan.c
@@ -30,6 +30,7 @@
 #include <stdio.h>
 #include <assert.h>
 #include <limits.h>
+#include <pthread_np.h>
 #ifdef HAVE_SYS_SYSCALL_H
 # include <sys/syscall.h>
 #endif
@@ -4332,11 +4333,7 @@ signal_op_complete:
 
 void *signaller_worker(void *arg)
 {
-#ifdef HAVE_SYS_SYSCALL_H
-    int unix_tid = syscall( __NR_gettid );
-#else
-    int unix_tid = -1;
-#endif
+    int unix_tid = pthread_getthreadid_np();
     struct wine_device *device = arg;
     struct wine_semaphore *sem;
     VkSemaphoreWaitInfo wait_info = { 0 };
