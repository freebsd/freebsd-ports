--- php_facedetect.h.orig	2020-10-25 08:22:36 UTC
+++ php_facedetect.h
@@ -32,5 +32,11 @@ PHP_FUNCTION(face_count);
 extern zend_module_entry facedetect_module_entry;
 #define phpext_facedetect_ptr &facedetect_module_entry
 
+#if PHP_VERSION_ID >= 80000
+#ifndef TSRMLS_CC
+#define TSRMLS_CC
+#endif
+#endif
+
 #endif
 
