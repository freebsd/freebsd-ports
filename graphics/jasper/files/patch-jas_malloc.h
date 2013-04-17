--- src/libjasper/include/jasper/jas_malloc.h.orig	2007-01-19 22:43:04.000000000 +0100
+++ src/libjasper/include/jasper/jas_malloc.h	2013-04-17 22:16:16.000000000 +0200
@@ -95,6 +95,9 @@
 #define	jas_free	MEMFREE
 #define	jas_realloc	MEMREALLOC
 #define	jas_calloc	MEMCALLOC
+#define	jas_malloc2(a, b)	MEMALLOC((a)*(b))
+#define	jas_malloc3(a, b, c)	MEMALLOC((a)*(b)*(c))
+#define	jas_realloc2(p, a, b)	MEMREALLOC((p), (a)*(b))
 #endif
 
 /******************************************************************************\
@@ -115,6 +118,13 @@
 /* Allocate a block of memory and initialize the contents to zero. */
 void *jas_calloc(size_t nmemb, size_t size);
 
+/* size-checked double allocation .*/
+void *jas_malloc2(size_t, size_t);
+
+void *jas_malloc3(size_t, size_t, size_t);
+
+void *jas_realloc2(void *, size_t, size_t);
+
 #endif
 
 #ifdef __cplusplus
