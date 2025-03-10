--- content/browser/media/media_keys_listener_manager_impl.cc.orig	2024-08-30 11:29:37 UTC
+++ content/browser/media/media_keys_listener_manager_impl.cc
@@ -337,7 +337,7 @@ void MediaKeysListenerManagerImpl::StartListeningForMe
     return;
   }
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || BUILDFLAG(IS_WIN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)) || BUILDFLAG(IS_WIN)
   // Create SystemMediaControls with the SingletonHwnd.
   browser_system_media_controls_ =
       system_media_controls::SystemMediaControls::Create(
