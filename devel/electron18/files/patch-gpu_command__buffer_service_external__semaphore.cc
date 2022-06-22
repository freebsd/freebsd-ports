--- gpu/command_buffer/service/external_semaphore.cc.orig	2022-05-19 05:17:42 UTC
+++ gpu/command_buffer/service/external_semaphore.cc
@@ -27,7 +27,7 @@ GLuint ImportSemaphoreHandleToGLSemaphore(SemaphoreHan
   if (!handle.is_valid())
     return 0;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   if (handle.vk_handle_type() !=
       VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD_BIT) {
     DLOG(ERROR) << "Importing semaphore handle of unexpected type:"
