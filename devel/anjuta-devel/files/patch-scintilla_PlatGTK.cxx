--- scintilla/PlatGTK.cxx.orig	Mon Sep 29 19:29:19 2003
+++ scintilla/PlatGTK.cxx	Sat Nov  8 05:00:37 2003
@@ -1034,7 +1034,7 @@
 static char *UTF8FromIconv(iconv_t iconvh, const char *s, int len) {
 	if (iconvh != ((iconv_t)(-1))) {
 		char *utfForm = new char[len*3+1];
-		char *pin = const_cast<char *>(s);
+		const char *pin = s;
 		size_t inLeft = len;
 		char *pout = utfForm;
 		size_t outLeft = len*3+1;
@@ -1051,7 +1051,7 @@
 static size_t MultiByteLenFromIconv(iconv_t iconvh, const char *s, size_t len) {
 	for (size_t lenMB=1; (lenMB<4) && (lenMB <= len); lenMB++) {
 		char wcForm[2];
-		char *pin = const_cast<char *>(s);
+		const char *pin = s;
 		size_t inLeft = lenMB;
 		char *pout = wcForm;
 		size_t outLeft = 2;
