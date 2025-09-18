--- media/audio/pulse/pulse_util.cc.orig	2025-08-26 20:49:50 UTC
+++ media/audio/pulse/pulse_util.cc
@@ -45,7 +45,11 @@ static const base::FilePath::CharType kPulseLib[] =
 
 #if defined(DLOPEN_PULSEAUDIO)
 static const base::FilePath::CharType kPulseLib[] =
+#if BUILDFLAG(IS_BSD)
+    FILE_PATH_LITERAL("libpulse.so");
+#else
     FILE_PATH_LITERAL("libpulse.so.0");
+#endif
 #endif
 
 void DestroyMainloop(pa_threaded_mainloop* mainloop) {
