--- src/af/util/xp/ut_iconv.cpp.orig	2009-06-25 02:52:27.000000000 +0200
+++ src/af/util/xp/ut_iconv.cpp	2009-10-27 22:43:07.000000000 +0100
@@ -264,10 +264,10 @@ const char * ucs4Internal ()
   // we special-case the win32 build, otherwise spelling and other stuff
   // just doesn't work
   return "UCS-4LE";
-#elif defined(_LIBICONV_H)
+#elif defined(_LIBICONV_H) || defined(__FreeBSD__)
   // libiconv seems to prefer UCS-4-INTERNAL to UCS-4BE and UCS-4LE
   return "UCS-4-INTERNAL";
-#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
+#elif defined(__OpenBSD__) || defined(__NetBSD__)
   // we special case the BSDs since spelling just doesn't work
   return "UCS4";
 #else
