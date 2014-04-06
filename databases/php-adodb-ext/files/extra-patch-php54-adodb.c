--- adodb.c.orig	2012-05-20 14:42:41.000000000 +0000
+++ adodb.c	2012-05-20 14:41:28.000000000 +0000
@@ -108,7 +108,7 @@
 }; 
 #else
 /* PHP 5 */
-function_entry adodb_functions[] = {
+zend_function_entry adodb_functions[] = {
    	PHP_FE(adodb_movenext,NULL) 
 	PHP_FE(adodb_getall,NULL)   
 	{NULL, NULL, NULL} 
