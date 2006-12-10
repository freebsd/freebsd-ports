--- fec.c.orig	Sat Dec  9 22:04:49 2006
+++ fec.c	Sat Dec  9 22:01:43 2006
@@ -3,6 +3,10 @@
  */
 
 #include <stdio.h>
+#include <errno.h>
+#include <stdlib.h>
+#include <sys/param.h>
+
 #include "fec.h"
 
 unsigned char Partab[256];
@@ -64,3 +68,30 @@
  5, 6, 6, 7, 6, 7, 7, 8,
 };
 
+#if __FreeBSD_version <700000
+
+int
+posix_memalign(void **memptr, size_t alignment, size_t size)
+{
+    int err;
+    void *result;
+
+    /* Make sure that alignment is a large enough power of 2. */
+    if (((alignment - 1) & alignment) != 0 || alignment < sizeof(void *))
+	    return (EINVAL);
+
+    /* 
+     * (size | alignment) is enough to assure the requested alignment, since
+     * the allocator always allocates power-of-two blocks.
+     */
+    err = errno; /* Protect errno against changes in pubrealloc(). */
+    result = malloc(size | alignment);
+    errno = err;
+
+    if (result == NULL)
+	return (ENOMEM);
+
+    *memptr = result;
+    return (0);
+}
+#endif
