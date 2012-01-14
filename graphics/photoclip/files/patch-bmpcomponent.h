--- bmpcomponent.h.orig	2006-08-15 09:44:29.000000000 +0200
+++ bmpcomponent.h	2012-01-14 09:06:32.000000000 +0100
@@ -15,7 +15,9 @@
 #else
 
 // Linux
+#if !defined(__FreeBSD__)
 #include <endian.h>
+#endif
 
 #endif // ! defined(__sun__)
 
