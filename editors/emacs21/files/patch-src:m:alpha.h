--- src/m/alpha.h.orig	Mon Oct  2 23:30:39 2000
+++ src/m/alpha.h	Wed Feb 13 09:05:57 2002
@@ -198,7 +198,7 @@
 
 #ifndef NOT_C_CODE
 /* We need these because pointers are larger than the default ints.  */
-#if !defined(__NetBSD__) && !defined(__OpenBSD__)
+#if !defined(__NetBSD__) && !defined(__OpenBSD__) && !defined(__FreeBSD__)
 #include <alloca.h>
 #endif
 
