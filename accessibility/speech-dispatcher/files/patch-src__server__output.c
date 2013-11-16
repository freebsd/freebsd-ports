--- ./src/server/output.c.orig	2012-07-11 11:05:06.000000000 +0200
+++ ./src/server/output.c	2013-11-15 11:18:27.066817985 +0100
@@ -30,22 +30,9 @@
 #include "output.h"
 #include "parse.h"
 
-#ifdef TEMP_FAILURE_RETRY	/* GNU libc */
-#define safe_write(fd, buf, count) TEMP_FAILURE_RETRY(write(fd, buf, count))
-#else /* TEMP_FAILURE_RETRY */
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>
 #endif
-static inline ssize_t
-safe_write(int fd, const void *buf, size_t count) {
-	do {
-		ssize_t w = write(fd, buf, count);
-
-		if (w == -1 && errno == EINTR) continue;
-		return w;
-	} while (1);
-}
-#endif /* TEMP_FAILURE_RETRY */
 
 #if !(defined(__GLIBC__) && defined(_GNU_SOURCE))
 /* Added by Willie Walker - strndup is a gcc-ism
