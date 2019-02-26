--- efence.c.orig	2019-02-26 17:53:52.941236000 +0100
+++ efence.c	2019-02-26 17:56:18.688752000 +0100
@@ -38,6 +38,7 @@
 # include <pthread.h>
 # include <semaphore.h>
 #endif
+#include <errno.h>
 
 #ifdef	malloc
 #undef	malloc
@@ -670,6 +671,27 @@
 	release();
 
 	return address;
+}
+
+extern C_LINKAGE int
+posix_memalign(void **memptr, size_t alignment, size_t userSize)
+{
+	/*
+	 * Per standard, posix_memalign returns EINVAL when alignment
+	 * is not a power of two or power of sizeof(void*).  efence
+	 * doesn't check the value of alignment in memalign, but then
+	 * again, memalign was never specified very well, and on some
+	 * systems odd alignments could indeed have been allowed.
+	 */
+	if ((alignment & (alignment - 1))
+	    || alignment % sizeof (void *))
+		return EINVAL;
+
+	void *ptr = memalign (alignment, userSize);
+	if (ptr == NULL)
+		return ENOMEM;
+	*memptr = ptr;
+	return 0;
 }
 
 /*
