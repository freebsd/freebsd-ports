--- gpu/command_buffer/client/test_shared_image_interface.cc.orig	2026-08-17 18:32:36 UTC
+++ gpu/command_buffer/client/test_shared_image_interface.cc
@@ -29,6 +29,8 @@
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 #include <linux/memfd.h>
+#endif
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <sys/mman.h>
 #include <unistd.h>
 #endif
@@ -426,7 +428,7 @@ TestSharedImageInterface::CreateSharedImageWithAsyncMa
   return image;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 scoped_refptr<ClientSharedImage>
 TestSharedImageInterface::CreateNativePixmapBackedSharedImage(
     const SharedImageInfo& si_info,
