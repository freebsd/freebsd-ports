--- src/lha_macro.h.orig	2000-10-04 14:57:38 UTC
+++ src/lha_macro.h
@@ -53,9 +53,10 @@
 #define SEEK_SET		0
 #define SEEK_CUR		1
 #define SEEK_END		2
-#endif	/* SEEK_SET
+#endif	/* SEEK_SET */
 
 
+#if 0
 /* non-integral functions */
 extern struct tm *localtime();
 extern char    *getenv();
@@ -69,6 +70,7 @@ extern char    *realloc();
 
 /* external variables */
 extern int      errno;
+#endif
 
 #define	FALSE			0
 #define TRUE			1
