--- ./mp3unicode.cpp.orig	2007-09-25 14:57:33.000000000 +0400
+++ ./mp3unicode.cpp	2007-09-29 15:16:49.000000000 +0400
@@ -200,9 +200,6 @@
 			if (
 				iconv (
 					cd,
-#if !defined(_LIBICONV_VERSION) || _LIBICONV_VERSION < 0x010B
-					(char **)
-#endif
 					&from,
 					&from_size,
 					&to,
