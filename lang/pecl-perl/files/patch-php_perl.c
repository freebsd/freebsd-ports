--- php_perl.c.orig	2014-04-05 15:09:01.511060907 +0600
+++ php_perl.c	2014-04-05 15:09:10.944074001 +0600
@@ -152,24 +152,33 @@
 
 /* Handlers for Perl objects overloading */
 static zend_object_value php_perl_clone(zval *object TSRMLS_DC);
+#if (ZEND_EXTENSION_API_NO >= 220100525)
+static zval* php_perl_read_property(zval *object, zval *member, int type, const struct _zend_literal *key TSRMLS_DC);
+static void php_perl_write_property(zval *object, zval *member, zval *value, const struct _zend_literal *key TSRMLS_DC);
+static int php_perl_has_property(zval *object, zval *member, int check_empty, const struct _zend_literal *key TSRMLS_DC);
+static void php_perl_unset_property(zval *object, zval *member, const struct _zend_literal *key TSRMLS_DC);
+#else
 static zval* php_perl_read_property(zval *object, zval *member, int type TSRMLS_DC);
 static void php_perl_write_property(zval *object, zval *member, zval *value TSRMLS_DC);
-static zval* php_perl_read_dimension(zval *object, zval *offset, int type TSRMLS_DC);
-static void php_perl_write_dimension(zval *object, zval *offset, zval *value TSRMLS_DC);
 static int php_perl_has_property(zval *object, zval *member, int check_empty TSRMLS_DC);
 static void php_perl_unset_property(zval *object, zval *member TSRMLS_DC);
+#endif
+static zval* php_perl_read_dimension(zval *object, zval *offset, int type TSRMLS_DC);
+static void php_perl_write_dimension(zval *object, zval *offset, zval *value TSRMLS_DC);
 static int php_perl_has_dimension(zval *object, zval *offset, int check_empty TSRMLS_DC);
 static void php_perl_unset_dimension(zval *object, zval *offset TSRMLS_DC);
 static HashTable* php_perl_get_properties(zval *object TSRMLS_DC);
-#if (ZEND_EXTENSION_API_NO >= 220041030)
+#if (ZEND_EXTENSION_API_NO >= 220100525)
+static zend_function *php_perl_get_method(zval **object_ptr, char *method, int method_len, const struct _zend_literal *key TSRMLS_DC);
+#elif (ZEND_EXTENSION_API_NO >= 220041030)
 static zend_function *php_perl_get_method(zval **object_ptr, char *method, int method_len TSRMLS_DC);
 #else
 static zend_function *php_perl_get_method(zval *object, char *method, int method_len TSRMLS_DC);
 #endif
-static int php_perl_call_function_handler(char *method, INTERNAL_FUNCTION_PARAMETERS);
+static int php_perl_call_function_handler(const char *method, INTERNAL_FUNCTION_PARAMETERS);
 static zend_function *php_perl_get_constructor(zval *object TSRMLS_DC);
 static zend_class_entry* php_perl_get_class_entry(const zval *object TSRMLS_DC);
-static int php_perl_get_class_name(const zval *object, char **class_name, zend_uint *class_name_len, int parent TSRMLS_DC);
+static int php_perl_get_class_name(const zval *object, const char **class_name, zend_uint *class_name_len, int parent TSRMLS_DC);
 static zval* php_perl_get(zval *object TSRMLS_DC);
 static void php_perl_set(zval **object, zval *value TSRMLS_DC);
 
@@ -241,9 +250,14 @@
   2,
   0,
   NULL,
-  0,
-  0,
+#if (ZEND_EXTENSION_API_NO >= 220100525)
+  php_perl_constructor_handler,
+  NULL
+#else
+  0, /* pass_rest_by_reference */
+  0, /* return_reference */
   php_perl_constructor_handler
+#endif
 };
 
 static SV* PerlIOPHP_getarg(pTHX_ PerlIO *f, CLONE_PARAMS *param, int flags)
@@ -866,7 +880,11 @@
       }
     }
   } else if (SvTYPE(sv) == SVt_PVHV) {
+#if (ZEND_EXTENSION_API_NO >= 220100525)
+    retval = php_perl_read_property(object, offset, type, NULL TSRMLS_CC);
+#else
     retval = php_perl_read_property(object, offset, type TSRMLS_CC);
+#endif
   } else {
     zend_error(E_WARNING, "[perl] Object is not an array");
   }
@@ -898,7 +916,11 @@
 
     av_store(av, Z_LVAL_P(offset), php_perl_zval_to_sv(my_perl, value TSRMLS_CC));
   } else if (SvTYPE(sv) == SVt_PVHV) {
+#if (ZEND_EXTENSION_API_NO >= 220100525)
+    php_perl_write_property(object, offset, value, NULL TSRMLS_CC);
+#else
     php_perl_write_property(object, offset, value TSRMLS_CC);
+#endif
   } else {
     zend_error(E_WARNING, "[perl] Object is not an array");
   }
@@ -941,7 +963,11 @@
       }
     }
   } else if (SvTYPE(sv) == SVt_PVHV) {
+#if (ZEND_EXTENSION_API_NO >= 220100525)
+    ret = php_perl_has_property(object, offset, check_empty, NULL TSRMLS_CC);
+#else
     ret = php_perl_has_property(object, offset, check_empty TSRMLS_CC);
+#endif
   } else {
     zend_error(E_WARNING, "[perl] Object is not an array");
   }
@@ -968,14 +994,22 @@
 
     av_delete(av, Z_LVAL_P(offset), G_DISCARD);
   } else if (SvTYPE(sv) == SVt_PVHV) {
+#if (ZEND_EXTENSION_API_NO >= 220100525)
+    php_perl_unset_property(object, offset, NULL TSRMLS_CC);
+#else
     php_perl_unset_property(object, offset TSRMLS_CC);
+#endif
   } else {
     zend_error(E_WARNING, "[perl] Object is not an array");
   }
 }
 
 /* Returns propery of hash based Perl's object */
+#if (ZEND_EXTENSION_API_NO >= 220100525)
+static zval* php_perl_read_property(zval *object, zval *member, int type, const struct _zend_literal *key TSRMLS_DC)
+#else
 static zval* php_perl_read_property(zval *object, zval *member, int type TSRMLS_DC)
+#endif
 {
   PerlInterpreter* my_perl = php_perl_init(TSRMLS_C);
   zval *retval = NULL;
@@ -1137,7 +1171,11 @@
 }
 
 /* Sets propery of hash based Perl's object */
-static void php_perl_write_property(zval *object, zval *member, zval *value TSRMLS_DC)
+#if (ZEND_EXTENSION_API_NO >= 220100525)
+static void php_perl_write_property(zval *object, zval *member, zval *value, const struct _zend_literal *key TSRMLS_DC)
+#else
+static void php_perl_write_property(zval *object, zval *member, zval *valueTSRMLS_DC)
+#endif
 {
   PerlInterpreter* my_perl = php_perl_init(TSRMLS_C);
   php_perl_object *obj = (php_perl_object*)zend_object_store_get_object(object TSRMLS_CC);
@@ -1229,7 +1267,11 @@
 }
 
 /* Checks if propery of hash based Perl's object isset or empty */
+#if (ZEND_EXTENSION_API_NO >= 220100525)
+static int php_perl_has_property(zval *object, zval *member, int check_empty, const struct _zend_literal *key TSRMLS_DC)
+#else
 static int php_perl_has_property(zval *object, zval *member, int check_empty TSRMLS_DC)
+#endif
 {
   int ret = 0;
   PerlInterpreter* my_perl = php_perl_init(TSRMLS_C);
@@ -1301,7 +1343,11 @@
 }
 
 /* Deletes propery of hash based Perl's object */
+#if (ZEND_EXTENSION_API_NO >= 220100525)
+static void php_perl_unset_property(zval *object, zval *member, const struct _zend_literal *key TSRMLS_DC)
+#else
 static void php_perl_unset_property(zval *object, zval *member TSRMLS_DC)
+#endif
 {
   PerlInterpreter* my_perl = php_perl_init(TSRMLS_C);
   php_perl_object *obj = (php_perl_object*)zend_object_store_get_object(object TSRMLS_CC);
@@ -1400,7 +1446,9 @@
 }
 
 /* get_method handler for overloaded Perl objects */
-#if (ZEND_EXTENSION_API_NO >= 220041030)
+#if (ZEND_EXTENSION_API_NO >= 220100525)
+static zend_function *php_perl_get_method(zval **object_ptr, char *method, int method_len, const struct _zend_literal *key TSRMLS_DC)
+#elif (ZEND_EXTENSION_API_NO >= 220041030)
 static zend_function *php_perl_get_method(zval **object_ptr, char *method, int method_len TSRMLS_DC)
 #else
 static zend_function *php_perl_get_method(zval *object, char *method, int method_len TSRMLS_DC)
@@ -1414,7 +1462,9 @@
 #endif
 
   if (obj->sv == NULL) {
-#if (ZEND_EXTENSION_API_NO >= 220041030)
+#if (ZEND_EXTENSION_API_NO >= 220100525)
+    zend_function *f = zend_get_std_object_handlers()->get_method(object_ptr, method, method_len, NULL TSRMLS_CC);
+#elif (ZEND_EXTENSION_API_NO >= 220041030)
     zend_function *f = zend_get_std_object_handlers()->get_method(object_ptr, method, method_len TSRMLS_CC);
 #else
     zend_function *f = zend_get_std_object_handlers()->get_method(object, method, method_len TSRMLS_CC);
@@ -1434,7 +1484,7 @@
 }
 
 /* Calls method of overloaded Perl's object */
-static int php_perl_call_function_handler(char *method, INTERNAL_FUNCTION_PARAMETERS)
+static int php_perl_call_function_handler(const char *method, INTERNAL_FUNCTION_PARAMETERS)
 {
   PerlInterpreter* my_perl = php_perl_init(TSRMLS_C);
   zval *object = this_ptr;
@@ -1493,13 +1543,13 @@
 //                         (memcmp(Z_STRVAL(zv), str, sizeof(str)-1) == 0))
       if (active_opline->opcode == ZEND_DO_FCALL &&
           active_opline->extended_value == 1 &&
-          active_opline->op1.op_type == IS_CONST &&
-          active_opline->op1.u.constant.type == IS_STRING &&
-          (ZSTRCMP(active_opline->op1.u.constant, "each") ||
-           ZSTRCMP(active_opline->op1.u.constant, "next") ||
-           ZSTRCMP(active_opline->op1.u.constant, "prev") ||
-           ZSTRCMP(active_opline->op1.u.constant, "key")  ||
-           ZSTRCMP(active_opline->op1.u.constant, "current"))) {
+          active_opline->op1_type == IS_CONST &&
+          active_opline->op1.constant &&
+          (ZSTRCMP(active_opline->op1.literal[active_opline->op1.constant].constant, "each") ||
+           ZSTRCMP(active_opline->op1.literal[active_opline->op1.constant].constant, "next") ||
+           ZSTRCMP(active_opline->op1.literal[active_opline->op1.constant].constant, "prev") ||
+           ZSTRCMP(active_opline->op1.literal[active_opline->op1.constant].constant, "key")  ||
+           ZSTRCMP(active_opline->op1.literal[active_opline->op1.constant].constant, "current"))) {
         return ht;
       }
     }
@@ -1547,7 +1597,7 @@
 }
 
 /* Returns class name of overloaded Perl's object */
-static int php_perl_get_class_name(const zval *object, char **class_name, zend_uint *class_name_len, int parent TSRMLS_DC)
+static int php_perl_get_class_name(const zval *object, const char **class_name, zend_uint *class_name_len, int parent TSRMLS_DC)
 {
   php_perl_object *obj = (php_perl_object*)zend_object_store_get_object(object TSRMLS_CC);
   SV* sv = obj->sv;
@@ -1839,7 +1889,7 @@
   php_info_print_table_start();
   php_info_print_table_header(2, "Perl support", "enabled");
   php_info_print_table_row(2, "Extension version", PHP_PERL_VERSION);
-  php_info_print_table_row(2, "Revision", "$Revision: 289243 $");
+  php_info_print_table_row(2, "Revision", "$Revision$");
   php_info_print_table_row(2, "Perl version", Perl_form(aTHX_ "%vd",PL_patchlevel));
   php_info_print_table_end();
 }
