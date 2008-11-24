$MirOS: ports/devel/ccache/patches/patch-util_c,v 1.1 2008/10/05 17:03:37 tg Exp $

	Very interesting bug: tries to read “size” bytes
	from “ptr” (of size “oldsize”) while copying to
	“p2” (of size “size”), instead of “oldsize” bytes;
	with mmap malloc, jemalloc, and possibly omalloc,
	the additional RAM needed is not always in core…

--- util.c.orig	Mon Sep 13 10:38:08 2004
+++ util.c	Sun Oct  5 16:58:39 2008
@@ -187,13 +187,9 @@ void *x_realloc(void *ptr, size_t size)
 {
 	void *p2;
 	if (!ptr) return x_malloc(size);
-	p2 = malloc(size);
+	p2 = realloc(ptr, size);
 	if (!p2) {
 		fatal("out of memory in x_realloc");
-	}
-	if (ptr) {
-		memcpy(p2, ptr, size);
-		free(ptr);
 	}
 	return p2;
 }
