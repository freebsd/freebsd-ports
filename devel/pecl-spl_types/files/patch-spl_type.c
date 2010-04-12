--- ./spl_type.c.orig	2010-04-12 13:52:44.000000000 -0400
+++ ./spl_type.c	2010-04-12 13:52:53.000000000 -0400
@@ -402,7 +402,7 @@
 	return spl_type_object_new_ex(class_type, 1, NULL, spl_type_set_float TSRMLS_CC);
 }
 /* {{{ Method and class definitions */
-static ZEND_BEGIN_ARG_INFO_EX(arg_SplType___construct, 0, 0, 0)
+ZEND_BEGIN_ARG_INFO_EX(arg_SplType___construct, 0, 0, 0)
 	ZEND_ARG_INFO(0, initial_value)
 	ZEND_ARG_INFO(0, strict)
 ZEND_END_ARG_INFO()
@@ -412,7 +412,7 @@
 	{NULL, NULL, NULL}
 };
 
-static ZEND_BEGIN_ARG_INFO_EX(arg_SplEnum_getConstList, 0, 0, 0)
+ZEND_BEGIN_ARG_INFO_EX(arg_SplEnum_getConstList, 0, 0, 0)
 	ZEND_ARG_INFO(0, include_default)
 ZEND_END_ARG_INFO()
 
