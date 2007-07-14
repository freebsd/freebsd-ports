--- defs.h.orig	Fri Apr 17 04:41:28 1998
+++ defs.h	Sun Jul 15 04:47:17 2007
@@ -27,6 +27,7 @@
 #define	bcopy(s, d, n)	memcpy(d, s, n)
 #define	bzero(p, n)	memset(p, 0, n)
 #else
+#include	<string.h>
 #include	<strings.h>
 #endif
 
@@ -35,21 +36,11 @@
 char *realloc();
 char *calloc();
 int free();
-#ifdef ANSI
-char *sprintf(char *, const char *, ...);
-#else
-char *sprintf();
-#endif
 #else
 void *malloc();
 void *realloc();
 void *calloc();
 void free();
-#ifdef ANSI
-int sprintf(char *, const char *, ...);
-#else
-int sprintf();
-#endif
 #endif
 char *mktemp();
 char *getenv();
