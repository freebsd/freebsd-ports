--- scintilla/PlatGTK.cxx.orig	Tue May 13 10:54:01 2003
+++ scintilla/PlatGTK.cxx	Tue May 13 10:55:23 2003
@@ -1032,7 +1032,7 @@
 static char *UTF8FromIconv(iconv_t iconvh, const char *s, int len) {
 	if (iconvh != ((iconv_t)(-1))) {
 		char *utfForm = new char[len*3+1];
-		char *pin = const_cast<char *>(s);
+		const char *pin = s;
 		size_t inLeft = len;
 		char *pout = utfForm;
 		size_t outLeft = len*3+1;
