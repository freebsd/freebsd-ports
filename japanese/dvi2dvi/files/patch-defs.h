--- defs.h.orig	Sat Aug 21 01:06:36 2004
+++ defs.h	Sat Aug 21 01:07:14 2004
@@ -35,21 +35,11 @@
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
