--- php_imagick.h.orig	2019-05-02 15:26:00 UTC
+++ php_imagick.h
@@ -47,5 +47,20 @@
 extern zend_module_entry imagick_module_entry;
 #define phpext_imagick_ptr &imagick_module_entry
 
+#if PHP_VERSION_ID >= 80000
+#ifndef TSRMLS_C
+#define TSRMLS_C
+#endif
+#ifndef TSRMLS_CC
+#define TSRMLS_CC
+#endif
+#ifndef TSRMLS_D
+#define TSRMLS_D
+#endif
+#ifndef TSRMLS_DC
+#define TSRMLS_DC
+#endif
+#endif
+
 #endif /* PHP_IMAGICK_H */
 
