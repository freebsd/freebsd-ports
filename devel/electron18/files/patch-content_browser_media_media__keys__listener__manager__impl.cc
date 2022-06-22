--- content/browser/media/media_keys_listener_manager_impl.cc.orig	2022-05-20 04:30:53 UTC
+++ content/browser/media/media_keys_listener_manager_impl.cc
@@ -237,7 +237,7 @@ void MediaKeysListenerManagerImpl::StartListeningForMe
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
 #if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   system_media_controls_ = system_media_controls::SystemMediaControls::Create(
       media::AudioManager::GetGlobalAppName());
 #endif
