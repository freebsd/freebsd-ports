--- ui/base/x/x11_shm_image_pool.cc.orig	2025-01-27 17:37:37 UTC
+++ ui/base/x/x11_shm_image_pool.cc
@@ -16,6 +16,7 @@
 #include "base/functional/callback.h"
 #include "base/location.h"
 #include "base/strings/string_util.h"
+#include "base/system/sys_info.h"
 #include "build/build_config.h"
 #include "net/base/url_util.h"
 #include "ui/events/platform/platform_event_dispatcher.h"
@@ -44,10 +45,14 @@ std::size_t MaxShmSegmentSizeImpl() {
     1.0f / (kShmResizeThreshold * kShmResizeThreshold);
 
 std::size_t MaxShmSegmentSizeImpl() {
+#if BUILDFLAG(IS_BSD)
+  return base::SysInfo::MaxSharedMemorySize();
+#else
   struct shminfo info;
   if (shmctl(0, IPC_INFO, reinterpret_cast<struct shmid_ds*>(&info)) == -1)
     return 0;
   return info.shmmax;
+#endif
 }
 
 std::size_t MaxShmSegmentSize() {
@@ -56,14 +61,19 @@ std::size_t MaxShmSegmentSize() {
 }
 
 #if !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_BSD)
 bool IsRemoteHost(const std::string& name) {
   if (name.empty())
     return false;
 
   return !net::HostStringIsLocalhost(name);
 }
+#endif
 
 bool ShouldUseMitShm(x11::Connection* connection) {
+#if BUILDFLAG(IS_BSD)
+  return false;
+#else
   // MIT-SHM may be available on remote connetions, but it will be unusable.  Do
   // a best-effort check to see if the host is remote to disable the SHM
   // codepath.  It may be possible in contrived cases for there to be a
@@ -92,6 +102,7 @@ bool ShouldUseMitShm(x11::Connection* connection) {
     return false;
 
   return true;
+#endif
 }
 #endif  // !BUILDFLAG(IS_CHROMEOS)
 
@@ -182,7 +193,7 @@ bool XShmImagePool::Resize(const gfx::Size& pixel_size
         shmctl(state.shmid, IPC_RMID, nullptr);
         return false;
       }
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       // On Linux, a shmid can still be attached after IPC_RMID if otherwise
       // kept alive.  Detach before XShmAttach to prevent a memory leak in case
       // the process dies.
@@ -201,7 +212,7 @@ bool XShmImagePool::Resize(const gfx::Size& pixel_size
         return false;
       state.shmseg = shmseg;
       state.shmem_attached_to_server = true;
-#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
       // The Linux-specific shmctl behavior above may not be portable, so we're
       // forced to do IPC_RMID after the server has attached to the segment.
       shmctl(state.shmid, IPC_RMID, nullptr);
