Index: tests/librnd/librnd_test.c
===================================================================
--- tests/librnd/librnd_test.c.orig	2021-06-11 15:14:52 UTC
+++ tests/librnd/librnd_test.c
@@ -22,12 +22,23 @@ static void poly_test()
 	rnd_poly_valid(&pa);
 }
 
+/* workaround for symbols missing out because of the static linking done with
+   the test app. Won't ever happen to real apps as they don't static link */
+#include <librnd/core/pixmap.h>
+static void (*workaround_fn)();
+static void librnd_test_symbol_workaround(void)
+{
+	workaround_fn = rnd_pixmap_reg_import;
+}
+
 int main(int argc, char *argv[])
 {
 	int n;
 	rnd_main_args_t ga;
 
 	rnd_app.default_embedded_menu = "";
+
+	librnd_test_symbol_workaround();
 
 	rnd_fix_locale_and_env();
 
