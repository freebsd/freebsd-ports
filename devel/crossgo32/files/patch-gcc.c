--- gcc/gcc.c.old	Wed May 19 15:29:39 2004
+++ gcc/gcc.c	Wed May 19 15:29:46 2004
@@ -175,7 +175,6 @@
 extern int errno;
 #endif
 
-extern int sys_nerr;
 #ifndef HAVE_STRERROR
 #if defined(bsd4_4)
 extern const char *const sys_errlist[];
