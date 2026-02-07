--- dtagnames.c.orig	2019-05-01 15:06:45 UTC
+++ dtagnames.c
@@ -7,16 +7,31 @@
 
 #include <stdio.h>
 #include <stdlib.h>
-#include <malloc.h>
+#ifdef __FreeBSD__
+#include <err.h>
+#include <malloc_np.h>
+#else
+#endif
 
 #include "dwarves.h"
 #include "dutil.h"
 
 static void print_malloc_stats(void)
 {
+#ifdef __FreeBSD__
+	int error;
+	size_t allocated, sz;
+
+	sz = sizeof(allocated);
+	error = mallctl("stats.active", &allocated, &sz, NULL, 0);
+	if (error != 0)
+		errc(1, error, "mallctl(stats.active)");
+	fprintf(stderr, "size: %zu\n", allocated);
+#else
 	struct mallinfo m = mallinfo();
 
 	fprintf(stderr, "size: %u\n", m.uordblks);
+#endif
 }
 
 static int class__tag_name(struct tag *tag, struct cu *cu __unused,
