--- geos.c.orig	2016-12-24 10:53:24 UTC
+++ geos.c
@@ -33,6 +33,13 @@
 /* Own stuff */
 #include "php_geos.h"
 
+#if PHP_MAJOR_VERSION >= 8
+#define TSRMLS_C
+#define TSRMLS_CC
+#define TSRMLS_DC
+#define TSRMLS_FETCH()
+#endif
+
 static ZEND_DECLARE_MODULE_GLOBALS(geos);
 static PHP_GINIT_FUNCTION(geos);
 
@@ -863,7 +870,7 @@ PHP_METHOD(Geometry, buffer)
     GEOS_PHP_ZVAL data;
     HashTable *style;
     zend_string *key;
-    ulong index;
+    zend_ulong index;
 
     this = (GEOSGeometry*)getRelay(getThis(), Geometry_ce_ptr);
 
@@ -956,7 +963,7 @@ PHP_METHOD(Geometry, offsetCurve)
     GEOS_PHP_ZVAL data;
     HashTable *style;
     zend_string *key;
-    ulong index;
+    zend_ulong index;
 
     this = (GEOSGeometry*)getRelay(getThis(), Geometry_ce_ptr);
 
