--- src/utils/ustring.cpp.orig	2013-09-24 11:33:12 UTC
+++ src/utils/ustring.cpp
@@ -203,7 +203,7 @@ static bool UTF8ToUTF16(const char *sour
         return false;
     }
 
-#if (defined(_LIBICONV_VERSION) && _LIBICONV_VERSION == 0x0109) || defined(__FreeBSD__)
+#if defined(_LIBICONV_VERSION) && _LIBICONV_VERSION == 0x0109
     // We are using an iconv API that uses const char*
     const char *sourceChar = source;
 #else
