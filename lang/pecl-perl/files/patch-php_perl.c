--- php_perl.c.orig	Sat Mar  3 18:01:30 2007
+++ php_perl.c	Sat Mar  3 18:01:38 2007
@@ -1779,7 +1779,7 @@
   perl_class_entry->get_iterator = php_perl_get_iterator;
 
   INIT_CLASS_ENTRY(perl_ce, "PerlException", NULL);
-  perl_exception_class_entry = zend_register_internal_class_ex(&perl_ce, zend_exception_get_default(), NULL TSRMLS_CC);
+  perl_exception_class_entry = zend_register_internal_class_ex(&perl_ce, zend_exception_get_default(TSRMLS_C), NULL TSRMLS_CC);
 
   return SUCCESS;
 }
