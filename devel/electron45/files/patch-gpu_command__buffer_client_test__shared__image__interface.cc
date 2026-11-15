--- gpu/command_buffer/client/test_shared_image_interface.cc.orig	2026-11-10 20:19:00 UTC
+++ gpu/command_buffer/client/test_shared_image_interface.cc
@@ -30,6 +30,8 @@
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 #include <linux/memfd.h>
+#endif
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <sys/mman.h>
 #include <unistd.h>
 #endif
@@ -437,7 +439,7 @@ TestSharedImageInterface::CreateSharedImageWithAsyncMa
   return image;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 scoped_refptr<ClientSharedImage>
 TestSharedImageInterface::CreateNativePixmapBackedSharedImage(
     const SharedImageInfo& si_info,
