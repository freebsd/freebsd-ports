--- ./runkit_sandbox.c.orig	2006-06-06 17:06:08.000000000 -0400
+++ ./runkit_sandbox.c	2010-04-13 00:04:47.000000000 -0400
@@ -728,7 +728,7 @@
 		/* ZE expects refcount == 0 for unowned values */
 		INIT_PZVAL(return_value);
 		PHP_SANDBOX_CROSS_SCOPE_ZVAL_COPY_CTOR(return_value);
-		return_value->refcount--;
+		Z_DELREF_P(return_value);
 
 		return return_value;
 	} else {
@@ -801,7 +801,7 @@
 		member_copy = *member;
 		member = &member_copy;
 		zval_copy_ctor(member);
-		member->refcount = 1;
+		Z_SET_REFCOUNT_P(member, 1);
 		convert_to_string(member);
 	}
 
@@ -875,7 +875,7 @@
 		member_copy = *member;
 		member = &member_copy;
 		zval_copy_ctor(member);
-		member->refcount = 1;
+		Z_SET_REFCOUNT_P(member, 1);
 		convert_to_string(member);
 	}
 
@@ -1391,7 +1391,7 @@
 
 		zval_copy_ctor(&callback_copy);
 		callback_copy.is_ref = 0;
-		callback_copy.refcount = 1;
+		Z_SET_REFCOUNT(callback_copy, 1);
 		callback_is_true = zval_is_true(&callback_copy);
 		zval_dtor(&callback_copy);
 	}
@@ -1411,7 +1411,7 @@
 	if (objval->output_handler && return_value_used) {
 		*return_value = *objval->output_handler;
 		zval_copy_ctor(return_value);
-		return_value->refcount = 1;
+		Z_SET_REFCOUNT_P(return_value, 1);
 		return_value->is_ref = 0;
 	} else {
 		RETVAL_FALSE;
@@ -1432,10 +1432,10 @@
 			MAKE_STD_ZVAL(cb);
 			*cb = *callback;
 			zval_copy_ctor(cb);
-			cb->refcount = 0;
-			cb->is_ref = 0;
+			Z_SET_REFCOUNT_P(cb, 0);
+			Z_UNSET_ISREF_P(cb);
 		}
-		cb->refcount++;
+		Z_ADDREF_P(cb);
 		objval->output_handler = cb;
 	}
 }
@@ -1469,8 +1469,8 @@
 	ALLOC_ZVAL(retval); \
 	Z_TYPE_P(retval) = IS_BOOL; \
 	Z_BVAL_P(retval) = objval->name; \
-	retval->refcount = 0; \
-	retval->is_ref = 0; \
+	Z_SET_REFCOUNT_P(retval, 0); \
+	Z_UNSET_ISREF_P(retval); \
 \
 	return retval; \
 }
@@ -1497,7 +1497,7 @@
 		zval_ptr_dtor(&objval->output_handler);
 	}
 
-	value->refcount++;
+	Z_ADDREF_P(value);
 	objval->output_handler = value;
 }
 
@@ -1512,7 +1512,7 @@
 	} else {
 		ZVAL_LONG(retval, objval->parent_scope);
 	}
-	retval->refcount = 0;
+	Z_SET_REFCOUNT_P(retval, 0);
 
 	return retval;
 }
@@ -1618,7 +1618,7 @@
 		member_copy = *member;
 		member = &member_copy;
 		zval_copy_ctor(member);
-		member->refcount = 1;
+		Z_SET_REFCOUNT_P(member, 1);
 		convert_to_string(member);
 	}
 
@@ -1654,7 +1654,7 @@
 		member_copy = *member;
 		member = &member_copy;
 		zval_copy_ctor(member);
-		member->refcount = 1;
+		Z_SET_REFCOUNT_P(member, 1);
 		convert_to_string(member);
 	}
 
@@ -1690,7 +1690,7 @@
 		member_copy = *member;
 		member = &member_copy;
 		zval_copy_ctor(member);
-		member->refcount = 1;
+		Z_SET_REFCOUNT_P(member, 1);
 		convert_to_string(member);
 	}
 
@@ -1714,7 +1714,6 @@
    * Class Definition *
    ******************** */
 
-static
 	ZEND_BEGIN_ARG_INFO_EX(php_runkit_require_two_args, 0, 0, 2)
 		ZEND_ARG_PASS_INFO(0)
 		ZEND_ARG_PASS_INFO(0)
