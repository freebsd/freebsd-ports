--- xhprof.c
+++ xhprof.c
@@ -28,6 +28,7 @@
 #include "php_ini.h"
 #include "ext/standard/info.h"
 #include "php_xhprof.h"
+#include "Zend/zend_extensions.h"
 #include <sys/time.h>
 #include <sys/resource.h>
 #include <stdlib.h>
@@ -898,7 +899,7 @@ static char *hp_get_base_filename(char *filename) {
 static char *hp_get_function_name(zend_op_array *ops TSRMLS_DC) {
   zend_execute_data *data;
   char              *func = NULL;
-  char              *cls = NULL;
+  const char        *cls = NULL;
   char              *ret = NULL;
   int                len;
   zend_function      *curr_func;
@@ -942,7 +943,12 @@ static char *hp_get_function_name(zend_op_array *ops TSRMLS_DC) {
       /* we are dealing with a special directive/function like
        * include, eval, etc.
        */
+#if ZEND_EXTENSION_API_NO >= 220100525
+      curr_op = data->opline->extended_value;
+#else
       curr_op = data->opline->op2.u.constant.value.lval;
+#endif
+
       switch (curr_op) {
         case ZEND_EVAL:
           func = "eval";
@@ -1660,13 +1666,22 @@ ZEND_DLEXPORT void hp_execute_internal(zend_execute_data *execute_data,
   if (!_zend_execute_internal) {
     /* no old override to begin with. so invoke the builtin's implementation  */
     zend_op *opline = EX(opline);
+#if ZEND_EXTENSION_API_NO >= 220100525
+    temp_variable *retvar = &EX_T(opline->result.var);
+    ((zend_internal_function *) EX(function_state).function)->handler(
+                       opline->extended_value,
+                       retvar->var.ptr,
+                       (EX(function_state).function->common.fn_flags & ZEND_ACC_RETURN_REFERENCE) ?
+                       &retvar->var.ptr:NULL,
+                       EX(object), ret TSRMLS_CC);
+#else
     ((zend_internal_function *) EX(function_state).function)->handler(
                        opline->extended_value,
                        EX_T(opline->result.u.var).var.ptr,
                        EX(function_state).function->common.return_reference ?
                        &EX_T(opline->result.u.var).var.ptr:NULL,
                        EX(object), ret TSRMLS_CC);
-
+#endif
   } else {
     /* call the old override */
     _zend_execute_internal(execute_data, ret TSRMLS_CC);
