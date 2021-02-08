--- gpu/command_buffer/service/external_semaphore.cc.orig	2021-01-07 00:36:35 UTC
+++ gpu/command_buffer/service/external_semaphore.cc
@@ -39,7 +39,7 @@ GLuint ImportSemaphoreHandleToGLSemaphore(SemaphoreHan
       },
       base::Time::Now()));
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
   if (handle.vk_handle_type() !=
       VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD_BIT) {
     DLOG(ERROR) << "Importing semaphore handle of unexpected type:"
