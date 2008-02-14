--- filec.c.orig	2008-02-14 11:54:22.713522435 +0100
+++ filec.c	2008-02-14 11:55:24.224617839 +0100
@@ -38,7 +38,7 @@
 
 #define isDotname(leaf) (!strcmp(leaf, ".") || !strcmp(leaf, ".."))
 
-#if defined(MISSING_EXTERN_ENVIRON) || (defined(__DJGPP__) && __DJGPP__ >= 2)
+#if defined(MISSING_EXTERN_ENVIRON) || (defined(__DJGPP__) && __DJGPP__ >= 2) || defined(__BSD_VISIBLE)
 extern char **environ;
 #endif
 
