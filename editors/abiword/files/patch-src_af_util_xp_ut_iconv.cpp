--- src/af/util/xp/ut_iconv.cpp.orig	2008-04-04 09:41:47.000000000 -0500
+++ src/af/util/xp/ut_iconv.cpp	2008-04-04 09:43:43.000000000 -0500
@@ -230,10 +230,10 @@
   // we special-case the win32 build, otherwise spelling and other stuff
   // just doesn't work
   return "UCS-2LE";
-#elif defined(_LIBICONV_H)
+#elif defined(_LIBICONV_H) || defined(__FreeBSD__)
   // libiconv seems to prefer UCS-2-INTERNAL to UCS-2BE and UCS-2LE
   return "UCS-2-INTERNAL";
-#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__QNXNTO__) || defined(__NetBSD__)
+#elif defined(__OpenBSD__) || defined(__QNXNTO__) || defined(__NetBSD__)
   // we special case the BSDs since spelling just doesn't work
   return "UCS2";
 #else
@@ -253,10 +253,10 @@
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
