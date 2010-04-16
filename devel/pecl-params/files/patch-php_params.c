--- ./php_params.c.orig	2010-04-16 19:41:28.000000000 -0400
+++ ./php_params.c	2010-04-16 19:45:52.000000000 -0400
@@ -65,7 +65,7 @@
 
 static inline int php_params_get_args(int *pargc, zval ***pargv TSRMLS_DC)
 {
-	void **p = EG(argument_stack).top_element - 2;
+	void **p = EG(argument_stack)->top - 2;
 	int pp_arg_count = PHP_PARAMS_INT_CAST *p;
 
 	p -= 1 + pp_arg_count;
@@ -75,7 +75,7 @@
 	}
 	--p;
 
-	if (p < EG(argument_stack).elements) {
+	if (p < ZEND_VM_STACK_ELEMETS(EG(argument_stack))) {
 		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Cannot use this function from the global scope");
 		return FAILURE;
 	}
@@ -476,7 +476,7 @@
 /* }}} */
 
 #ifdef ZEND_ENGINE_2
-static ZEND_BEGIN_ARG_INFO_EX(params_parse_arginfo, 0, ZEND_RETURN_VALUE, 1)
+ZEND_BEGIN_ARG_INFO_EX(params_parse_arginfo, 0, ZEND_RETURN_VALUE, 1)
 	ZEND_ARG_INFO(0, format)
 ZEND_END_ARG_INFO()
 #else
