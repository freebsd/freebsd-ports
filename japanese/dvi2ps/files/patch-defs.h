--- defs.h.orig	Tue May 18 03:17:26 2004
+++ defs.h	Tue May 18 03:15:26 2004
@@ -51,21 +51,11 @@
 char *realloc();
 char *calloc();
 int free();
-#ifdef ANSI
-char *sprintf(char *, const char *, ...);
-#else
-char *sprintf();
-#endif
 #else /* POSIX */
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
