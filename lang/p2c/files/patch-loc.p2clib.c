--- loc.p2clib.c.orig	1993-12-08 05:36:53 UTC
+++ loc.p2clib.c
@@ -4,3 +4,42 @@
  * the symbol LOCAL_INIT when you compile p2clib.c.
  */
 
+/* Some Turbo "unit crt" functions. */
+
+#include <curses.h>
+#include <term.h>
+
+static int terminfo_initialized;
+static char *cl, *ce;
+
+static void initcurs()
+{
+    if (terminfo_initialized)
+	return;
+    setupterm(0, fileno(stdout), 0);
+    ce = tgetstr("ce", 0);
+    cl = tgetstr("cl", 0);
+    terminfo_initialized = 1;
+}
+
+void clreol()
+{
+    initcurs();
+    if (ce)
+	tputs(ce, 1, putchar);
+}
+
+void clrscr()
+{
+    initcurs();
+    if (cl)
+	tputs(cl, 1, putchar);
+}
+
+void delay(ms)
+int ms;
+{
+    usleep(1000 * ms);
+}
+
+
