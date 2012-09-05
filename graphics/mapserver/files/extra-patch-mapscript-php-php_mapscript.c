--- mapscript/php/php_mapscript.c.orig	2012-09-05 14:31:32.000000000 +0800
+++ mapscript/php/php_mapscript.c	2012-09-05 14:32:04.000000000 +0800
@@ -899,7 +899,7 @@
 
 }
 
-function_entry mapscript_functions[] = {
+zend_function_entry mapscript_functions[] = {
     PHP_FE(ms_GetVersion, NULL)
     PHP_FE(ms_GetVersionInt,  NULL)
     PHP_FE(ms_newLineObj, NULL)
