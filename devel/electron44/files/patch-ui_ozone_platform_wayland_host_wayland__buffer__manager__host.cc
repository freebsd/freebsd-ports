--- ui/ozone/platform/wayland/host/wayland_buffer_manager_host.cc.orig	2026-03-13 16:54:03 UTC
+++ ui/ozone/platform/wayland/host/wayland_buffer_manager_host.cc
@@ -46,9 +46,13 @@ bool CheckImportExportFence() {
 }
 
 bool CheckImportExportFence() {
+#if BUILDFLAG(IS_BSD)
+  return false;
+#else
   // DMA_BUF_IOCTL_{IMPORT,EXPORT}_SYNC_FILE was added in 6.0
   return base::SysInfo::KernelVersionNumber::Current() >=
          base::SysInfo::KernelVersionNumber(6, 0);
+#endif
 }
 
 }  // namespace
