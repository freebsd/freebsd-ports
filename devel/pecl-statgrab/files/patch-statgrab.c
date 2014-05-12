--- ./statgrab.c.orig	2006-11-07 22:14:38.000000000 +0000
+++ ./statgrab.c	2014-05-10 02:12:48.502985234 +0100
@@ -22,7 +22,7 @@
 #include "config.h"
 #endif
 
-#include <statgrab.h>
+#include <statgrab0.h>
 
 #include "php.h"
 #include "php_ini.h"
@@ -69,7 +69,7 @@
  *
  * Every user visible function must have an entry in statgrab_functions[].
  */
-function_entry statgrab_functions[] = {
+zend_function_entry statgrab_functions[] = {
 	PHP_FE(sg_cpu_percent_usage,	NULL)
 	PHP_FE(sg_cpu_totals,		NULL)
 	PHP_FE(sg_cpu_diff,		NULL)
