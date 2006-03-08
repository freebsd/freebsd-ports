--- utils.c.orig	Wed Mar  8 22:53:21 2006
+++ utils.c	Wed Mar  8 22:53:37 2006
@@ -187,7 +187,7 @@
 {
    void *p;
 
-#ifdef __linux__
+#if defined(__linux__) || HAS_POSIX_MEMALIGN
    if (posix_memalign((void *)&p,boundary,size))
 #else
 #ifdef __CYGWIN__
