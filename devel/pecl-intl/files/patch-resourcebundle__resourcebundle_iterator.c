--- ./resourcebundle/resourcebundle_iterator.c.orig	2010-04-13 10:38:51.000000000 -0400
+++ ./resourcebundle/resourcebundle_iterator.c	2010-04-13 10:39:13.000000000 -0400
@@ -75,7 +75,7 @@
 
 	resourcebundle_iterator_invalidate( iter TSRMLS_CC );
 
-	object->refcount--;
+	Z_DELREF_P(object);
 
 	efree(iterator);
 }
@@ -162,7 +162,7 @@
 	     php_error( E_ERROR, "ResourceBundle does not support writable iterators" );
 	}
 
-	object->refcount++;
+	Z_ADDREF_P(object);
 	iterator->intern.data = (void *) object;
 	iterator->intern.funcs = &resourcebundle_iterator_funcs;
 
