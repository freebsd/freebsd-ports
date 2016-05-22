--- src/calibre/utils/imageops/imageops.cpp.orig	2016-05-20 11:45:27 UTC
+++ src/calibre/utils/imageops/imageops.cpp
@@ -582,9 +582,9 @@ QImage despeckle(const QImage &image) { 
 
 // overlay() {{{ 
 static inline unsigned int BYTE_MUL(unsigned int x, unsigned int a) {
-    quint64 t = (((quint64(x)) | ((quint64(x)) << 24)) & 0x00ff00ff00ff00ff) * a;
-    t = (t + ((t >> 8) & 0xff00ff00ff00ff) + 0x80008000800080) >> 8;
-    t &= 0x00ff00ff00ff00ff;
+    quint64 t = (((quint64(x)) | ((quint64(x)) << 24)) & 0x00ff00ff00ff00ffULL) * a;
+    t = (t + ((t >> 8) & 0xff00ff00ff00ffULL) + 0x80008000800080ULL) >> 8;
+    t &= 0x00ff00ff00ff00ffULL;
     return ((unsigned int)(t)) | ((unsigned int)(t >> 24));
 }
 
