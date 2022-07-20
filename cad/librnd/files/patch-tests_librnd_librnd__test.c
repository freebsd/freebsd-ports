Index: tests/librnd/librnd_test.c
===================================================================
--- tests/librnd/librnd_test.c.orig	2022-05-11 07:25:34 UTC
+++ tests/librnd/librnd_test.c
@@ -15,6 +15,15 @@
 
 /*** init test ***/
 
+/* workaround for symbols missing out because of the static linking done with
+   the test app. Won't ever happen to real apps as they don't static link */
+#include <librnd/core/pixmap.h>
+static void (*workaround_fn)();
+static void librnd_test_symbol_workaround(void)
+{
+	workaround_fn = rnd_pixmap_reg_import;
+}
+
 static void poly_test()
 {
 	rnd_polyarea_t pa;
