--- ./php_perl.c.orig	2010-04-12 19:11:06.000000000 -0400
+++ ./php_perl.c	2010-04-12 19:16:41.000000000 -0400
@@ -340,14 +340,14 @@
 {
   SV* sv;
 
-  if ((zv->is_ref || Z_TYPE_P(zv) == IS_OBJECT || Z_TYPE_P(zv) == IS_ARRAY) &&
+  if ((Z_ISREF_P(zv) || Z_TYPE_P(zv) == IS_OBJECT || Z_TYPE_P(zv) == IS_ARRAY) &&
       zend_hash_find(var_hash, (char*)zv, sizeof(zv), (void**)&sv) == SUCCESS) {
     sv = *(SV**)sv;
     SvREFCNT_inc(sv);
     return sv;
   }
   sv = php_perl_zval_to_sv_noref(my_perl, zv, var_hash TSRMLS_CC);
-  if (zv->is_ref || Z_TYPE_P(zv) == IS_OBJECT || Z_TYPE_P(zv) == IS_ARRAY) {
+  if (Z_ISREF_P(zv) || Z_TYPE_P(zv) == IS_OBJECT || Z_TYPE_P(zv) == IS_ARRAY) {
     zend_hash_add(var_hash, (char*)zv, sizeof(zv), &sv, sizeof(SV*), NULL);
   }
   return sv;
@@ -390,7 +390,7 @@
         SV* sv = (SV*)newRV((SV*)hv);
         zval** zv_ptr;
 
-        if (zv->is_ref || Z_TYPE_P(zv) == IS_ARRAY) {
+        if (Z_ISREF_P(zv) || Z_TYPE_P(zv) == IS_ARRAY) {
           zend_hash_add(var_hash, (char*)zv, sizeof(zv), &sv, sizeof(SV*), NULL);
         }
 
@@ -420,7 +420,7 @@
         SV* sv = (SV*)newRV((SV*)av);
         zval** zv_ptr;
 
-        if (zv->is_ref || Z_TYPE_P(zv) == IS_ARRAY) {
+        if (Z_ISREF_P(zv) || Z_TYPE_P(zv) == IS_ARRAY) {
           zend_hash_add(var_hash, (char*)zv, sizeof(zv), &sv, sizeof(SV*), NULL);
         }
 
@@ -480,9 +480,9 @@
       FREE_ZVAL(zv);
     }
     if (Z_TYPE_PP(z) != IS_OBJECT) {
-      (*z)->is_ref = 1;
+      Z_SET_ISREF_P((*z));
     }
-    (*z)->refcount++;
+    Z_ADDREF_P((*z));
     return *z;
   }
 
@@ -750,7 +750,7 @@
   }
   retval = php_perl_sv_to_zval(my_perl, obj->sv, NULL TSRMLS_CC);
   /* ensure we're creating a temporary variable */
-  if (retval) {retval->refcount = 0;}
+  if (retval) {Z_SET_REFCOUNT_P(retval, 0);}
   return retval;
 }
 
@@ -824,8 +824,8 @@
         obj->context = PERL_SCALAR;
 
         ALLOC_INIT_ZVAL(retval);
-        retval->refcount = 0;
-        retval->is_ref = 1;
+        Z_SET_REFCOUNT_P(retval, 0);
+        Z_SET_ISREF_P(retval);
         retval->type = IS_OBJECT;
         Z_OBJ_HT_P(retval) = &php_perl_proxy_handlers;
         Z_OBJ_HANDLE_P(retval) = zend_objects_store_put(obj, php_perl_destructor, NULL, NULL TSRMLS_CC);        
@@ -833,7 +833,7 @@
         ALLOC_INIT_ZVAL(retval);
         retval = php_perl_sv_to_zval(my_perl, *prop_val, retval TSRMLS_CC);
         /* ensure we're creating a temporary variable */
-        if (retval) {retval->refcount = 0;}
+        if (retval) {Z_SET_REFCOUNT_P(retval, 0);}
       }
     }
   } else if (SvTYPE(sv) == SVt_PVHV) {
@@ -973,7 +973,7 @@
       new_obj->properties = NULL;
 
       ALLOC_INIT_ZVAL(new_object);
-      new_object->refcount = 0;
+      Z_SET_REFCOUNT_P(new_object, 0);
       new_object->type = IS_OBJECT;
       new_object->value.obj.handlers = &php_perl_object_handlers;
       new_object->value.obj.handle =
@@ -990,7 +990,7 @@
       new_obj->properties = NULL;
 
       ALLOC_INIT_ZVAL(new_object);
-      new_object->refcount = 0;
+      Z_SET_REFCOUNT_P(new_object, 0);
       new_object->type = IS_OBJECT;
       new_object->value.obj.handlers = &php_perl_object_handlers;
       new_object->value.obj.handle =
@@ -1007,7 +1007,7 @@
       new_obj->properties = NULL;
 
       ALLOC_INIT_ZVAL(new_object);
-      new_object->refcount = 0;
+      Z_SET_REFCOUNT_P(new_object, 0);
       new_object->type = IS_OBJECT;
       new_object->value.obj.handlers = &php_perl_object_handlers;
       new_object->value.obj.handle =
@@ -1085,15 +1085,15 @@
       obj->context = PERL_SCALAR;
 
       ALLOC_INIT_ZVAL(retval);
-      retval->refcount = 0;
-      retval->is_ref = 1;
+      Z_SET_REFCOUNT_P(retval, 0);
+      Z_SET_ISREF_P(retval);
       retval->type = IS_OBJECT;
       Z_OBJ_HT_P(retval) = &php_perl_proxy_handlers;
       Z_OBJ_HANDLE_P(retval) = zend_objects_store_put(obj, php_perl_destructor, NULL, NULL TSRMLS_CC);        
     } else {
       retval = php_perl_sv_to_zval(my_perl, sv, retval TSRMLS_CC);
       /* ensure we're creating a temporary variable */
-      if (retval) {retval->refcount = 0;}
+      if (retval) {Z_SET_REFCOUNT_P(retval, 0);}
     }
   }
 
@@ -1755,7 +1755,7 @@
 zend_object_iterator *php_perl_get_iterator(zend_class_entry *ce, zval *object TSRMLS_DC)
 {
   zend_object_iterator *iterator = emalloc(sizeof(zend_object_iterator));
-  object->refcount++;
+  Z_ADDREF_P(object);
   iterator->data = (void*)object;
   iterator->funcs = &php_perl_iterator_funcs;
 
