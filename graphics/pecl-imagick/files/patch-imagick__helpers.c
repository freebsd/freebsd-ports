--- imagick_helpers.c.orig	2020-10-25 08:02:44 UTC
+++ imagick_helpers.c
@@ -113,7 +113,9 @@ MagickBooleanType php_imagick_progress_monitor_callabl
 #endif
 	fci.param_count = 2;
 	fci.params = zargs;
+#if PHP_VERSION_ID < 80000
 	fci.no_separation = 0;
+#endif
 #if PHP_VERSION_ID < 70100
 	fci.symbol_table = NULL;
 #endif
