--- ./resourcebundle/resourcebundle_class.c.orig	2010-04-13 10:38:08.000000000 -0400
+++ ./resourcebundle/resourcebundle_class.c	2010-04-13 10:38:25.000000000 -0400
@@ -212,7 +212,7 @@
 	MAKE_STD_ZVAL(retval);
 
 	resourcebundle_array_fetch(object, offset, retval, 1 TSRMLS_CC);
-	retval->refcount--;
+	Z_DELREF_P(retval);
 	return retval;
 }
 /* }}} */
