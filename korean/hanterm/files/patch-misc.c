--- misc.c.orig	Tue Jan  8 19:41:11 2002
+++ misc.c	Fri Oct 25 12:10:43 2002
@@ -904,18 +904,7 @@
 #endif
     int n;
 {
-#if defined(linux) && defined(__GLIBC__)
-    extern const char *const sys_errlist[];
-#else
-#if (defined(BSD) && (BSD >= 199306))
-    /* in *BSD, should be null because it is already declared */
-#else
-    extern char *sys_errlist[];
-#endif
-#endif
-    extern int sys_nerr;
-
-    return ((n >= 0 && n < sys_nerr) ? sys_errlist[n] : "unknown error");
+	return (strerror(n));
 }
 
 
