--- tests/test-utils.c.orig	2020-03-07 01:31:18 UTC
+++ tests/test-utils.c
@@ -376,5 +376,4 @@ test_utils_print_dependency_versions (void)
     g_test_message ("Cairo version:    %s", cairo_version_string ());
     g_test_message ("Pango version:    %s", pango_version_string ());
     g_test_message ("Freetype version: %d.%d.%d", ft_major, ft_minor, ft_patch);
-    g_test_message ("Harfbuzz version: %s", hb_version_string ());
 }
