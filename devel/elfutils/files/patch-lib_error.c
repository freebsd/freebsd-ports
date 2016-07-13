--- lib/error.c.orig	2016-07-13 06:58:54 UTC
+++ lib/error.c
@@ -0,0 +1,64 @@
+#include <err.h>
+#include <errno.h>
+#include <stdarg.h>
+#include <stdio.h>
+
+#include "error.h"
+
+unsigned int error_message_count;
+int error_one_per_line;
+void (*error_print_progname)(void) = NULL;
+
+static const char *lastfile;
+static unsigned lastline;
+
+/* Good enough. */
+
+void
+error_at_line(int status, int errnum, const char *fn, unsigned line,
+    const char *format, ...)
+{
+	va_list ap;
+	int serrno;
+
+	if (error_one_per_line != 0 && fn != NULL && fn == lastfile && line ==
+	    lastline)
+		return;
+
+	serrno = errno;
+	errno = errnum;
+
+	fflush(stdout);
+
+	if (error_print_progname != NULL) {
+		error_print_progname();
+		fprintf(stderr, ":");
+	}
+
+	if (fn != NULL) {
+		lastfile = fn;
+		lastline = line;
+
+		fprintf(stderr, "%s:%u: ", fn, line);
+	} else if (error_print_progname != NULL) {
+		fprintf(stderr, " ");
+	}
+
+	va_start(ap, format);
+	if (status) {
+		if (errnum)
+			verr(status, format, ap);
+		else
+			verrx(status, format, ap);
+	} else {
+		if (errnum)
+			vwarn(format, ap);
+		else
+			vwarnx(format, ap);
+	}
+	va_end(ap);
+
+	errno = serrno;
+	error_message_count++;
+}
+
