--- glob/glob.h.orig	Sat Jan 22 00:43:03 2000
+++ glob/glob.h	Fri Aug 23 02:37:03 2002
@@ -47,6 +47,9 @@
 
 /* We need `size_t' for the following definitions.  */
 #ifndef __size_t
+#if defined __FreeBSD__
+#define __size_t size_t
+#else
 # if defined __GNUC__ && __GNUC__ >= 2
 typedef __SIZE_TYPE__ __size_t;
 # else
@@ -59,6 +62,7 @@
  */
 #if !(defined __DECC && defined __SIZE_T)
 typedef unsigned long int __size_t;
+#endif
 #endif
 # endif
 #else
