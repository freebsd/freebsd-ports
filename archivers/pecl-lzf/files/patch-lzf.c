--- ./lzf.c.orig	2009-03-02 17:53:17.000000000 +0300
+++ ./lzf.c	2012-06-06 10:11:48.202502799 +0400
@@ -37,7 +37,7 @@
 *
 * Every user visible function must have an entry in lzf_functions[].
 */
-function_entry lzf_functions[] = {
+zend_function_entry lzf_functions[] = {
 	PHP_FE(lzf_compress,		NULL)
 	PHP_FE(lzf_decompress,		NULL)
 	PHP_FE(lzf_optimized_for,	NULL)
