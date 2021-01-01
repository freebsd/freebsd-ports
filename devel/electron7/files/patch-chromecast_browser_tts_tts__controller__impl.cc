--- chromecast/browser/tts/tts_controller_impl.cc.orig	2019-12-12 12:39:27 UTC
+++ chromecast/browser/tts/tts_controller_impl.cc
@@ -390,7 +390,11 @@ int TtsControllerImpl::QueueSize() {
 }
 
 TtsPlatformImpl* TtsControllerImpl::GetPlatformImpl() {
+#if defined(OS_BSD)
+  return NULL;
+#else
   return platform_impl_.get();
+#endif // defined(OS_BSD)
 }
 
 std::string TtsControllerImpl::GetApplicationLocale() const {
