--- dtagnames.c.orig	2016-06-30 19:30:28 UTC
+++ dtagnames.c
@@ -9,16 +9,33 @@
 
 #include <stdio.h>
 #include <stdlib.h>
-#include <malloc.h>
+
+/* For mallctl */
+#include <err.h>
+#include <errno.h>
+#include <malloc_np.h>
 
 #include "dwarves.h"
 #include "dutil.h"
 
 static void print_malloc_stats(void)
 {
+#if 0
 	struct mallinfo m = mallinfo();
 
 	fprintf(stderr, "size: %u\n", m.uordblks);
+#else
+	size_t allocated, olen;
+	int rc;
+
+	olen = sizeof(allocated);
+	rc = mallctl("stats.allocated", &allocated, &olen, NULL, 0);
+	if (rc != 0) {
+		errno = rc;
+		err(1, "mallctl stats.allocated");
+	}
+	fprintf(stderr, "size: %zu\n", allocated);
+#endif
 }
 
 static int class__tag_name(struct tag *tag, struct cu *cu __unused,
