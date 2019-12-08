--- geos.c.orig	2016-12-24 10:53:24 UTC
+++ geos.c
@@ -863,7 +863,7 @@ PHP_METHOD(Geometry, buffer)
     GEOS_PHP_ZVAL data;
     HashTable *style;
     zend_string *key;
-    ulong index;
+    zend_ulong index;
 
     this = (GEOSGeometry*)getRelay(getThis(), Geometry_ce_ptr);
 
@@ -956,7 +956,7 @@ PHP_METHOD(Geometry, offsetCurve)
     GEOS_PHP_ZVAL data;
     HashTable *style;
     zend_string *key;
-    ulong index;
+    zend_ulong index;
 
     this = (GEOSGeometry*)getRelay(getThis(), Geometry_ce_ptr);
 
