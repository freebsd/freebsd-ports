--- content/public/common/content_switches.h.orig	2019-09-10 11:14:02 UTC
+++ content/public/common/content_switches.h
@@ -268,7 +268,7 @@ CONTENT_EXPORT extern const char kRendererWaitForJavaD
 CONTENT_EXPORT extern const char kDisablePanelFitting[];
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_FREEBSD)
 CONTENT_EXPORT extern const char kEnableSpeechDispatcher[];
 #endif
 
