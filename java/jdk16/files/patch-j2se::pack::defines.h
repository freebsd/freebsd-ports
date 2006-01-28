--- ../../j2se/src/share/native/com/sun/java/util/jar/pack/defines.h	Tue Oct 19 14:59:48 2004
+++ ../../j2se/src/share/native/com/sun/java/util/jar/pack/defines.h	Sun Oct 16 09:06:04 2005
@@ -15,4 +15,8 @@
 #endif
 
+#ifndef NO_ZLIB
+#	include <zconf.h>
+#endif
+
 #ifndef FULL
 #define FULL 1 /* Adds <500 bytes to the zipped final product. */
@@ -70,4 +74,5 @@
 
 typedef unsigned int uint;
+#ifdef NO_ZLIB
 #ifdef _LP64
 typedef unsigned int uLong; // Historical zlib, should be 32-bit.
@@ -75,4 +80,6 @@
 typedef unsigned long uLong;
 #endif
+#endif
+
 #ifdef _MSC_VER 
 typedef LONGLONG 	jlong;
