--- content/browser/media/media_keys_listener_manager_impl.cc.orig	2023-08-20 00:00:06 UTC
+++ content/browser/media/media_keys_listener_manager_impl.cc
@@ -238,7 +238,7 @@ void MediaKeysListenerManagerImpl::StartListeningForMe
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
 #if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   system_media_controls_ = system_media_controls::SystemMediaControls::Create(
       media::AudioManager::GetGlobalAppName());
 #endif
