--- chromecast/browser/cast_content_browser_client.cc.orig	2019-04-08 08:32:48 UTC
+++ chromecast/browser/cast_content_browser_client.cc
@@ -524,7 +524,7 @@ void CastContentBrowserClient::AppendExtraCommandLineS
                                           switches::kAudioOutputChannels));
     }
   } else if (process_type == switches::kGpuProcess) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Necessary for accelerated 2d canvas.  By default on Linux, Chromium assumes
   // GLES2 contexts can be lost to a power-save mode, which breaks GPU canvas
   // apps.
