--- lib/stdio_ext.h.orig	2016-07-13 06:58:54 UTC
+++ lib/stdio_ext.h
@@ -0,0 +1,16 @@
+#pragma once
+#include <stdio.h>
+
+enum {
+	FSETLOCKING_QUERY,
+	FSETLOCKING_INTERNAL,
+	FSETLOCKING_BYCALLER,
+};
+
+static inline int
+__fsetlocking(FILE *fp __unused, int type __unused)
+{
+
+	/* No-op on FreeBSD? */
+	return (FSETLOCKING_BYCALLER);
+}
