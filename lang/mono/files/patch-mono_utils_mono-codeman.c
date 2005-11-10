--- mono/utils/mono-codeman.c.orig	Tue Aug  2 17:52:22 2005
+++ mono/utils/mono-codeman.c	Tue Aug  2 17:52:29 2005
@@ -40,7 +40,11 @@
 #endif
 #endif
 
-#ifdef __x86_64__
+#if defined(__x86_64__) && defined(__FreeBSD__)
+#define FORCE_MALLOC
+#endif
+
+#if defined(__x86_64__) && !defined(__FreeBSD__)
 #define ARCH_MAP_FLAGS MAP_32BIT
 #else
 #define ARCH_MAP_FLAGS 0
@@ -282,7 +286,7 @@
 	chunk->pos = bsize;
 	chunk->bsize = bsize;
 
-	/*printf ("code chunk at: %p\n", ptr);*/
+	//printf ("code chunk at: %p\n", ptr);
 	return chunk;
 }
 
