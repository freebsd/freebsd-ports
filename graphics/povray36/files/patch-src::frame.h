--- src/frame.h.orig	Tue Jan  7 10:08:30 2003
+++ src/frame.h	Sun Dec 28 23:37:04 2003
@@ -44,12 +44,20 @@
 class pov_istream_class;
 class pov_ostream_class;
 
+#if defined(__LP64__) || defined(__alpha__)
+typedef unsigned int u_int32 ;
+#else
 typedef unsigned long u_int32 ;
+#endif
 typedef unsigned short u_int16 ;
 typedef unsigned char u_int8 ;
 typedef unsigned char byte ;
 
+#if defined(__LP64__) || defined(__alpha__)
+typedef signed int int32 ;
+#else
 typedef signed long int32 ;
+#endif
 typedef signed short int16 ;
 typedef signed char int8 ;
 
