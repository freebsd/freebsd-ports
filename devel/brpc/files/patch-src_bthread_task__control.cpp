--- src/bthread/task_control.cpp.orig	2026-02-23 02:11:29 UTC
+++ src/bthread/task_control.cpp
@@ -374,6 +374,14 @@ void TaskControl::bind_thread_to_cpu(pthread_t pthread
             LOG(WARNING) << "Failed to bind thread to cpu: " << cpu_id;
         }
         (void)r;
+#elif defined(OS_FREEBSD)
+        cpuset_t cs;
+        CPU_ZERO(&cs);
+        CPU_SET(cpu_id, &cs);
+        if (cpuset_setaffinity(CPU_LEVEL_WHICH, CPU_WHICH_TID, -1,
+                               sizeof(cs), &cs) != 0) {
+            LOG(WARNING) << "Failed to bind thread to cpu: " << cpu_id;
+        }
 #elif defined(OS_MACOSX)
         thread_port_t mach_thread = pthread_mach_thread_np(pthread);
         if (mach_thread != MACH_PORT_NULL) {
