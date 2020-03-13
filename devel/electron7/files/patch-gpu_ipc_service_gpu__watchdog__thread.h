--- gpu/ipc/service/gpu_watchdog_thread.h.orig	2019-12-12 12:39:44 UTC
+++ gpu/ipc/service/gpu_watchdog_thread.h
@@ -234,8 +234,10 @@ class GPU_IPC_SERVICE_EXPORT GpuWatchdogThreadImplV1
   XDisplay* display_;
   gfx::AcceleratedWidget window_;
   XAtom atom_;
+#if !defined(OS_BSD)
   FILE* tty_file_;
   int host_tty_;
+#endif
 #endif
 
   base::WeakPtrFactory<GpuWatchdogThreadImplV1> weak_factory_{this};
