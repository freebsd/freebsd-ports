--- scintilla/ScintillaGTK.cxx.orig	Tue May 13 10:57:21 2003
+++ scintilla/ScintillaGTK.cxx	Tue May 13 10:58:24 2003
@@ -876,7 +876,7 @@
 					iconv_t iconvh = iconv_open("UTF8", source);
 					if (iconvh != ((iconv_t)(-1))) {
 						char localeVal[4]="\0\0\0";
-						char *pin = utfVal;
+						const char *pin = utfVal;
 						size_t inLeft = strlen(utfVal);
 						char *pout = localeVal;
 						size_t outLeft = sizeof(localeVal);
