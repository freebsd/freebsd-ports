
$FreeBSD$

--- ../include/xsw_ctype.h.orig	Fri Feb  9 02:18:26 2001
+++ ../include/xsw_ctype.h	Fri Feb  9 12:40:01 2001
@@ -1,6 +1,7 @@
 // xsw_ctype.h
 // This is intended as a prototype for files using the global/ctype.cpp file.
 
+#ifndef __FreeBSD__
 #if defined(__cplusplus) || defined(c_plusplus)
 
 extern bool isblank(char c);
@@ -11,5 +12,6 @@
 extern int isblank( int );
 
 #endif	// __cplusplus || c_plusplus
+#endif	// __FreeBSD__
 
 extern void ctype_dummy_func();
