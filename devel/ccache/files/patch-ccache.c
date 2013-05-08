$FreeBSD$

Disable compiling preprocessed code on CURRENT with default clang. Avoids
needing to define CCACHE_CPP2 to build with clang. Performance hit but
much safer until upstream fixes the build issue.

--- ./ccache.c.orig	2013-05-08 14:22:16.891630019 -0500
+++ ./ccache.c	2013-05-08 14:27:18.488628070 -0500
@@ -31,6 +31,9 @@
 #include "hashutil.h"
 #include "language.h"
 #include "manifest.h"
+#if defined(__FreeBSD__)
+#include <sys/param.h>
+#endif
 
 static const char VERSION_TEXT[] =
 MYNAME " version %s\n"
@@ -2260,7 +2263,11 @@
 		base_dir = NULL;
 	}
 
+#if __FreeBSD_version >= 1000024
+	compile_preprocessed_source_code = false;
+#else
 	compile_preprocessed_source_code = !getenv("CCACHE_CPP2");
+#endif
 
 	/* make sure the cache dir exists */
 	if (create_dir(cache_dir) != 0) {
