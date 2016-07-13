--- lib/vasnprintf.h.orig	2016-07-13 08:19:27 UTC
+++ lib/vasnprintf.h
@@ -0,0 +1,23 @@
+#pragma once
+#include <stdarg.h>
+#include <stdio.h>
+
+static inline char *
+vasnprintf(char *resultbuf, size_t *lengthp, const char *format, va_list args)
+{
+	char *alloc;
+	int len;
+
+	len = vasprintf(&alloc, format, args);
+	if (len < 0)
+		return (NULL);
+
+	*lengthp = len;
+
+	if (resultbuf != NULL && (size_t)len < *lengthp) {
+		memcpy(resultbuf, alloc, len + 1);
+		free(alloc);
+		return (resultbuf);
+	}
+	return (alloc);
+}
