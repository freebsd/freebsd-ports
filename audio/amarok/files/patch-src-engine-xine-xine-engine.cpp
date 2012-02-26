--- amarok/src/engine/xine/xine-engine.cpp.orig
+++ amarok/src/engine/xine/xine-engine.cpp
@@ -1131,7 +1131,11 @@ bool XineEngine::metaDataForUrl(const KU
 
 bool XineEngine::getAudioCDContents(const QString &device, KURL::List &urls)
 {
+#if XINE_MAJOR_VERSION < 1 || (XINE_MAJOR_VERSION == 1 && XINE_MINOR_VERSION < 2)
     char **xine_urls = NULL;
+#else
+    const char * const *xine_urls = NULL;
+#endif
     int num;
     int i = 0;
 
