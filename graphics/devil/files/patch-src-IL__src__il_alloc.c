--- src-IL/src/il_alloc.c.orig	2009-03-08 10:10:09.000000000 +0300
+++ src-IL/src/il_alloc.c	2014-10-07 01:39:56.201078445 +0400
@@ -123,7 +123,7 @@
 {
 	if (ptr)
 	{
-#ifdef MM_MALLOC
+#if defined(VECTORMEM) && defined(MM_MALLOC)
 	    _mm_free((void*)ptr);
 #else
 #if defined(VECTORMEM) & !defined(POSIX_MEMALIGN) & !defined(VALLOC) & !defined(MEMALIGN) & !defined(MM_MALLOC)
