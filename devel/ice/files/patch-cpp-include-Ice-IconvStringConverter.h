--- cpp/include/Ice/IconvStringConverter.h.orig	2013-10-04 15:48:14 UTC
+++ cpp/include/Ice/IconvStringConverter.h
@@ -20,7 +20,7 @@
 #include <langinfo.h>
 #endif
 
-#if (defined(__APPLE__) && _LIBICONV_VERSION < 0x010B) || defined(__FreeBSD__)
+#if (defined(__APPLE__) && _LIBICONV_VERSION < 0x010B)
     //
     // See http://sourceware.org/bugzilla/show_bug.cgi?id=2962
     //
