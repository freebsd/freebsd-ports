--- lib/error.h.orig	2016-07-13 06:58:54 UTC
+++ lib/error.h
@@ -0,0 +1,18 @@
+#pragma once
+
+/*
+ * error, error_at_line, error_message_count, error_one_per_line,
+ * error_print_progname - glibc error reporting functions
+ */
+
+/* void error(int status, int errnum, const char *format, ...); */
+#define	error(st, en, ...)	error_at_line(st, en, NULL, 0, __VA_ARGS__)
+
+void error_at_line(int status, int errnum, const char *filename,
+    unsigned int linenum, const char *format, ...);
+
+extern unsigned int error_message_count;
+
+extern int error_one_per_line;
+
+extern void (*error_print_progname) (void);
