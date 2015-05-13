--- src/core/linux/convhelper.cpp.orig	2014-01-10 21:18:20 UTC
+++ src/core/linux/convhelper.cpp
@@ -36,7 +36,7 @@
 #error This file is not for Windows.
 #endif
 
-#if defined(__FreeBSD__) || defined(__NetBSD__)
+#if defined(__NetBSD__)
 #define HAVE_ICONV_CONST
 #endif
 
