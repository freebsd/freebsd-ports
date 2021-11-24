--- chrome/browser/sharing/sharing_handler_registry_impl.cc.orig	2021-07-15 19:13:34 UTC
+++ chrome/browser/sharing/sharing_handler_registry_impl.cc
@@ -21,10 +21,10 @@
 #include "chrome/browser/sharing/shared_clipboard/shared_clipboard_message_handler_desktop.h"
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 #include "chrome/browser/sharing/shared_clipboard/remote_copy_message_handler.h"
-#endif  // defined(OS_WIN) || defined(OS_MAC) || (defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MAC) || (defined(OS_LINUX) || defined(OS_BSD) ||
         // BUILDFLAG(IS_CHROMEOS_LACROS)) defined(OS_CHROMEOS)
 
 SharingHandlerRegistryImpl::SharingHandlerRegistryImpl(
@@ -67,14 +67,14 @@ SharingHandlerRegistryImpl::SharingHandlerRegistryImpl
         {chrome_browser_sharing::SharingMessage::kSharedClipboardMessage});
   }
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
   if (sharing_device_registration->IsRemoteCopySupported()) {
     AddSharingHandler(
         std::make_unique<RemoteCopyMessageHandler>(profile),
         {chrome_browser_sharing::SharingMessage::kRemoteCopyMessage});
   }
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 }
 
