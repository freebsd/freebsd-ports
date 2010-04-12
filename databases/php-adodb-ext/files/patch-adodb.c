--- adodb.c.orig	2010-04-12 20:00:43.000000000 +0800
+++ adodb.c	2010-04-12 20:05:20.000000000 +0800
@@ -159,11 +159,11 @@
 
 static void adodb_init_zval(zval *v, char *s)
 {
-	v->type = IS_STRING;
-	v->value.str.val = s;
-	v->value.str.len = strlen(s);
-	v->is_ref = 0;
-	v->refcount = 1;
+	Z_TYPE_P(v) = IS_STRING;
+	Z_STRVAL_P(v) = s;
+	Z_STRLEN_P(v) = strlen(s);
+	Z_UNSET_ISREF_P(v);
+	Z_SET_REFCOUNT_P(v, 1);
 }
 
 /* {{{ PHP_MINIT_FUNCTION
@@ -277,7 +277,7 @@
 	fci.function_table = EG(function_table);
 	fci.function_name = &adodb_zvals[zval_ocifetch];
 	fci.symbol_table = NULL;
-	fci.object_pp = NULL;
+	fci.object_ptr = NULL;
 	fci.retval_ptr_ptr = &retval;
 	fci.param_count = 2;
 	fci.params = &params[1];
