--- remoting/host/basic_desktop_environment.cc.orig	2023-05-25 00:42:01 UTC
+++ remoting/host/basic_desktop_environment.cc
@@ -188,7 +188,7 @@ BasicDesktopEnvironment::CreateVideoCapturer() {
   scoped_refptr<base::SingleThreadTaskRunner> capture_task_runner;
 #if BUILDFLAG(IS_CHROMEOS_ASH)
   capture_task_runner = ui_task_runner_;
-#elif BUILDFLAG(IS_LINUX) && defined(REMOTING_USE_WAYLAND)
+#elif (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(REMOTING_USE_WAYLAND)
   // Each capturer instance should get its own thread so the capturers don't
   // compete with each other in multistream mode.
   capture_task_runner = base::ThreadPool::CreateSingleThreadTaskRunner(
