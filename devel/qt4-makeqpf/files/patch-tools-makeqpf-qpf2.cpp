--- qpf2.cpp	Sun Jul  8 08:08:09 2007
+++ qpf2.cpp	Sun Jul  8 08:08:33 2007
@@ -342,6 +342,8 @@
     int startGlyphIndex;
 };
 
+#define log2(x) log(x)/log(2)
+
 static QByteArray generateTrueTypeCMap(QFontEngine *fe)
 {
     QByteArray cmap;
