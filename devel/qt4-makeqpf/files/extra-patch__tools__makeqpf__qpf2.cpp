--- tools/makeqpf/qpf2.cpp.orig	2009-09-07 13:00:31.000000000 +0200
+++ tools/makeqpf/qpf2.cpp	2009-09-21 22:15:11.717123200 +0200
@@ -363,6 +363,8 @@
     int startGlyphIndex;
 };
 
+#define log2(x) log(x)/log(2)
+
 static QByteArray generateTrueTypeCMap(QFontEngine *fe)
 {
     QByteArray cmap;
