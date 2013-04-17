--- src/libjasper/base/jas_malloc.c.orig	2007-01-19 22:43:05.000000000 +0100
+++ src/libjasper/base/jas_malloc.c	2013-04-17 22:43:09.000000000 +0200
@@ -76,6 +76,9 @@
 
 /* We need the prototype for memset. */
 #include <string.h>
+#include <limits.h>
+#include <errno.h>
+#include <stdint.h>
 
 #include "jasper/jas_malloc.h"
 
@@ -113,19 +116,51 @@
 
 void *jas_realloc(void *ptr, size_t size)
 {
-	return realloc(ptr, size);
+	return ptr ? realloc(ptr, size) : malloc(size);
 }
 
 void *jas_calloc(size_t nmemb, size_t size)
 {
 	void *ptr;
+
+	ptr = jas_malloc2(nmemb, size);
+	if (ptr)
+		memset(ptr, 0, nmemb*size);
+	return ptr;
+}
+
+void *jas_realloc2(void *ptr, size_t nmemb, size_t size)
+{
+	if (!ptr)
+		return jas_malloc2(nmemb, size);
+	if (nmemb && SIZE_MAX / nmemb < size) {
+		errno = ENOMEM;
+		return NULL;
+	}
+	return jas_realloc(ptr, nmemb * size);
+
+}
+
+void *jas_malloc2(size_t nmemb, size_t size)
+{
+	if (nmemb && SIZE_MAX / nmemb < size) {
+		errno = ENOMEM;
+		return NULL;
+	}
+
+	return jas_malloc(nmemb * size);
+}
+
+void *jas_malloc3(size_t a, size_t b, size_t c)
+{
 	size_t n;
-	n = nmemb * size;
-	if (!(ptr = jas_malloc(n * sizeof(char)))) {
-		return 0;
+
+	if (a && SIZE_MAX / a < b) {
+		errno = ENOMEM;
+		return NULL;
 	}
-	memset(ptr, 0, n);
-	return ptr;
+
+	return jas_malloc2(a*b, c);
 }
 
 #endif
