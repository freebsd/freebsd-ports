--- ui/ozone/platform/wayland/host/wayland_buffer_manager_host.cc.orig	2026-01-07 00:52:53 UTC
+++ ui/ozone/platform/wayland/host/wayland_buffer_manager_host.cc
@@ -45,9 +45,13 @@ bool CheckImportExportFence() {
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
