--- src/utils/src/utils/ustring.cpp.orig	2018-10-19 17:18:23 UTC
+++ src/utils/src/utils/ustring.cpp
@@ -171,7 +171,7 @@ static bool UTF8ToUTF16(const std::string& source, uin
         return false;
     }
 
-#if (defined(_LIBICONV_VERSION) && _LIBICONV_VERSION == 0x0109) || defined(__FreeBSD__)
+#if defined(_LIBICONV_VERSION) && _LIBICONV_VERSION == 0x0109
     // We are using an iconv API that uses const char*
     const char *sourceChar = source.c_str();
 #else
