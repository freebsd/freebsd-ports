--- gdal_wrap.cpp.orig	2012-10-09 00:58:28 UTC
+++ gdal_wrap.cpp
@@ -932,7 +932,7 @@ SWIG_ZTS_ConvertResourcePtr(zval *z, swi
   p = value->ptr;
   if (type==-1) return NULL;
 
-  type_name=zend_rsrc_list_get_rsrc_type(z->value.lval TSRMLS_CC);
+  type_name=(char *) zend_rsrc_list_get_rsrc_type(z->value.lval TSRMLS_CC);
 
   return SWIG_ZTS_ConvertResourceData(p, type_name, ty TSRMLS_CC);
 }
@@ -1423,6 +1423,7 @@ t_output_helper( zval **target, zval *o)
     return;
   }
   if ( (*target)->type == IS_NULL ) {
+    TSRMLS_FETCH();
     REPLACE_ZVAL_VALUE(target,o,1);
     FREE_ZVAL(o);
     return;
