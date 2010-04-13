--- ./php_runkit.h.orig	2006-06-06 17:06:08.000000000 -0400
+++ ./php_runkit.h	2010-04-13 00:04:47.000000000 -0400
@@ -41,6 +41,13 @@
 #define PHP_RUNKIT_IMPORT_CLASSES			(PHP_RUNKIT_IMPORT_CLASS_METHODS|PHP_RUNKIT_IMPORT_CLASS_CONSTS|PHP_RUNKIT_IMPORT_CLASS_PROPS)
 #define PHP_RUNKIT_IMPORT_OVERRIDE			0x0010
 
+#if ZEND_MODULE_API_NO > 20050922
+#define ZEND_ENGINE_2_2
+#endif
+#if ZEND_MODULE_API_NO > 20050921
+#define ZEND_ENGINE_2_1
+#endif
+
 /* The TSRM interpreter patch required by runkit_sandbox was added in 5.1, but this package includes diffs for older versions
  * Those diffs include an additional #define to indicate that they've been applied
  */
