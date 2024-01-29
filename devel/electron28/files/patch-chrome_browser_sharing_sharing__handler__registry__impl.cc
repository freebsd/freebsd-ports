--- chrome/browser/sharing/sharing_handler_registry_impl.cc.orig	2022-10-24 13:33:33 UTC
+++ chrome/browser/sharing/sharing_handler_registry_impl.cc
@@ -23,7 +23,7 @@
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/sharing/shared_clipboard/remote_copy_message_handler.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || (BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS_LACROS)) BUILDFLAG(IS_CHROMEOS)
@@ -77,7 +77,7 @@ SharingHandlerRegistryImpl::SharingHandlerRegistryImpl
   }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (sharing_device_registration->IsRemoteCopySupported()) {
     AddSharingHandler(
         std::make_unique<RemoteCopyMessageHandler>(profile),
