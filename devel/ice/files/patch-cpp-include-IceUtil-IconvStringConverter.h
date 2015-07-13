--- cpp/include/IceUtil/IconvStringConverter.h.orig	2013-10-04 15:48:14 UTC
+++ cpp/include/IceUtil/IconvStringConverter.h
@@ -14,11 +14,11 @@
 #include <IceUtil/UndefSysMacros.h>
 
 #include <algorithm>
 #include <iconv.h>
 #include <langinfo.h>
 #include <string.h> // For strerror
 
-#if (defined(__APPLE__) && _LIBICONV_VERSION < 0x010B) || defined(__FreeBSD__)
+#if (defined(__APPLE__) && _LIBICONV_VERSION < 0x010B)
     //
     // See http://sourceware.org/bugzilla/show_bug.cgi?id=2962
     //
