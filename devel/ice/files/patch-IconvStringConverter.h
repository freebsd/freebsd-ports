--- cpp/include/Ice/IconvStringConverter.h.orig	2008-05-22 19:27:55.000000000 +0200
+++ cpp/include/Ice/IconvStringConverter.h	2008-05-22 19:28:22.000000000 +0200
@@ -19,7 +19,7 @@
 #include <langinfo.h>
 #endif
 
-#if (defined(__APPLE__) && _LIBICONV_VERSION < 0x010B) || (defined(__sun) && !defined(_XPG6))
+#if (defined(__APPLE__) && _LIBICONV_VERSION < 0x010B) || (defined(__sun) && !defined(_XPG6)) || defined(__FreeBSD__)
     //
     // See http://sourceware.org/bugzilla/show_bug.cgi?id=2962
     //
