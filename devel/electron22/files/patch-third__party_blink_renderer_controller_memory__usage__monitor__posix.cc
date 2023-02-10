--- third_party/blink/renderer/controller/memory_usage_monitor_posix.cc.orig	2022-06-17 14:20:10 UTC
+++ third_party/blink/renderer/controller/memory_usage_monitor_posix.cc
@@ -129,15 +129,17 @@ void MemoryUsageMonitorPosix::ResetFileDescriptors() {
 
 void MemoryUsageMonitorPosix::SetProcFiles(base::File statm_file,
                                            base::File status_file) {
+#if !BUILDFLAG(IS_BSD)
   DCHECK(statm_file.IsValid());
   DCHECK(status_file.IsValid());
   DCHECK_EQ(-1, statm_fd_.get());
   DCHECK_EQ(-1, status_fd_.get());
   statm_fd_.reset(statm_file.TakePlatformFile());
   status_fd_.reset(status_file.TakePlatformFile());
+#endif
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // static
 void MemoryUsageMonitorPosix::Bind(
     mojo::PendingReceiver<mojom::blink::MemoryUsageMonitorLinux> receiver) {
