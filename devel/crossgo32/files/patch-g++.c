--- gcc/cp/g++.c.old	Wed May 19 15:33:04 2004
+++ gcc/cp/g++.c	Wed May 19 15:33:19 2004
@@ -92,7 +92,6 @@
 extern int errno;
 #endif
 
-extern int sys_nerr;
 #ifndef HAVE_STRERROR
 #if defined(bsd4_4)
 extern const char *const sys_errlist[];
