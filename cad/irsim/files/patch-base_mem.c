--- base/mem.c.orig	2018-06-25 17:36:40 UTC
+++ base/mem.c
@@ -126,7 +126,7 @@ extern	unsigned  sleep();
 #define	PAGE_MASK		( PAGE_SIZE - 1 )
 
 #define	FPRINTF			(void) fprintf
-#if defined(CYGWIN) || defined(__APPLE__)
+#if defined(CYGWIN) || defined(__APPLE__) || defined(__FreeBSD__)
 private Pointer GetMoreCore( npages )
   int  npages;
   {
