--- osr_wrap.cpp.orig	2012-10-09 08:58:28.000000000 +0800
+++ osr_wrap.cpp	2013-03-02 01:50:03.170201473 +0800
@@ -932,7 +932,7 @@
   p = value->ptr;
   if (type==-1) return NULL;
 
-  type_name=zend_rsrc_list_get_rsrc_type(z->value.lval TSRMLS_CC);
+  type_name=(char *) zend_rsrc_list_get_rsrc_type(z->value.lval TSRMLS_CC);
 
   return SWIG_ZTS_ConvertResourceData(p, type_name, ty TSRMLS_CC);
 }
@@ -1147,6 +1147,7 @@
     return;
   }
   if ( (*target)->type == IS_NULL ) {
+    TSRMLS_FETCH();
     REPLACE_ZVAL_VALUE(target,o,1);
     FREE_ZVAL(o);
     return;
