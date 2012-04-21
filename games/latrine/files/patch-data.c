--- data.c.orig	2009-07-16 03:10:29.000000000 +0900
+++ data.c	2012-04-10 22:49:26.000000000 +0900
@@ -26,6 +26,17 @@
 #include <stdlib.h>
 #include <string.h>
 
+#include <sys/param.h>
+#if __FreeBSD_version < 800067
+#define NO_WCSCASECMP
+#endif
+
+#if defined(NO_WCSCASECMP)
+#include <wchar.h>
+#include <wctype.h>
+#define wcscasecmp __wcscasecmp
+#endif
+
 #include "charset.h"
 #include "latrine.h"
 #include "memory.h"
@@ -912,6 +923,22 @@
 	return 0;
 }
 
+#if defined(NO_WCSCASECMP)
+int
+__wcscasecmp(const wchar_t *s1, const wchar_t *s2)
+{
+	wchar_t c1, c2;
+
+	for (; *s1; s1++, s2++) {
+		c1 = towlower(*s1);
+		c2 = towlower(*s2);
+		if (c1 != c2)
+			return ((int)c1 - c2);
+	}
+	return (-*s2);
+}
+#endif
+
 int
 wordcmp(struct word *w[2], const int ignore_case)
 {
