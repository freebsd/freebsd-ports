
$FreeBSD$

--- misc/glob.h	2002/09/23 16:45:45	1.1
+++ misc/glob.h	2002/09/23 16:46:23
@@ -46,7 +46,7 @@
 #endif /* C++ or ANSI C.  */
 
 /* We need `size_t' for the following definitions.  */
-#ifndef __size_t
+#if !defined(__size_t) && !defined(_SIZE_T_DECLARED)
 # if defined __GNUC__ && __GNUC__ >= 2
 typedef __SIZE_TYPE__ __size_t;
 #  ifdef _XOPEN_SOURCE
