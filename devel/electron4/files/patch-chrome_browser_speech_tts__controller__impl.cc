--- chrome/browser/speech/tts_controller_impl.cc.orig	2019-03-16 09:15:21 UTC
+++ chrome/browser/speech/tts_controller_impl.cc
@@ -449,9 +449,13 @@ int TtsControllerImpl::QueueSize() {
 }
 
 TtsPlatformImpl* TtsControllerImpl::GetPlatformImpl() {
+#if defined(OS_BSD)
+  return NULL;
+#else
   if (!platform_impl_)
     platform_impl_ = TtsPlatformImpl::GetInstance();
   return platform_impl_;
+#endif
 }
 
 int TtsControllerImpl::GetMatchingVoice(
