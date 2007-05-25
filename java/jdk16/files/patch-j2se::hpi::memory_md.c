--- ../../j2se/src/solaris/hpi/src/memory_md.c
+++ ../../j2se/src/solaris/hpi/src/memory_md.c
@@ -32,7 +32,9 @@
 #include <stdlib.h>
 #include <stdio.h>	/* For perror() */
 #include <string.h>
-#if !defined(_ALLBSD_SOURCE)
+#if defined(_ALLBSD_SOURCE)
+#include <sys/param.h>
+#else
 #include <malloc.h>
 #endif
 
@@ -67,7 +69,16 @@
 static size_t memGrainSize;	/* A page for Linux */
 #elif defined(_ALLBSD_SOURCE)
 static size_t memGrainSize;	/* A page for FreeBSD */
+#if defined(__FreeBSD__) && (__FreeBSD_version >= 700013)
+static inline void *
+memalign(size_t alignment, size_t size)
+{
+    void *ret;
+    return posix_memalign(&ret, alignment, size) ? NULL : ret;
+}
+#else
 #define memalign(a, b)	valloc(b)
+#endif
 #else
 static unsigned int memGrainSize;	/* A page for Solaris */
 #endif
