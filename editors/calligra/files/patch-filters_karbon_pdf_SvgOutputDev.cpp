--- filters/karbon/pdf/SvgOutputDev.cpp.orig	2026-04-09 04:19:06 UTC
+++ filters/karbon/pdf/SvgOutputDev.cpp
@@ -386,7 +386,11 @@ QString SvgOutputDev::printStroke()
     return stroke;
 }
 
+#if POPPLER_VERSION_MACRO < QT_VERSION_CHECK(26, 4, 0)
 void SvgOutputDev::drawString(GfxState *state, const GooString *s)
+#else
+void SvgOutputDev::drawString(GfxState *state, const std::string &s)
+#endif
 {
     int render = state->getRender();
     // check for invisible text -- this is used by Acrobat Capture
@@ -397,8 +401,10 @@ void SvgOutputDev::drawString(GfxState *state, const G
     // ignore empty strings
 #if POPPLER_VERSION_MACRO < QT_VERSION_CHECK(25, 10, 0)
     if (s->getLength() == 0) {
-#else
+#elif POPPLER_VERSION_MACRO < QT_VERSION_CHECK(26, 4, 0)
     if (s->size() == 0) {
+#else
+    if (s.empty()) {
 #endif
         return;
     }
@@ -407,11 +413,15 @@ void SvgOutputDev::drawString(GfxState *state, const G
 
     QString str;
 
-    const char *p = s->c_str();
 #if POPPLER_VERSION_MACRO < QT_VERSION_CHECK(25, 10, 0)
+    const char *p = s->c_str();
     int len = s->getLength();
-#else
+#elif POPPLER_VERSION_MACRO < QT_VERSION_CHECK(26, 4, 0)
+    const char *p = s->c_str();
     int len = s->size();
+#else
+    const char *p = s.c_str();
+    int len = s.size();
 #endif
     CharCode code;
     const Unicode *u = nullptr;
