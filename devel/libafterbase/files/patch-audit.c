--- audit.c.orig	Sun Oct  7 22:16:37 2001
+++ audit.c	Sun Oct  7 22:19:10 2001
@@ -427,7 +427,7 @@
 	m1->line = line;
 #else
 	safefree (m->ptr);
-	mem_destroy( (ASHashableValue)NULL, m );
+	mem_destroy( (ASHashableValue)(void*)NULL, m );
 #endif
 }
 
@@ -714,7 +714,7 @@
 */
 
 	XFreePixmap (display, pmap);
-	mem_destroy( (ASHashableValue)NULL, m );
+	mem_destroy( (ASHashableValue)(void*)NULL, m );
 	return Success;
 }
 
@@ -750,7 +750,7 @@
 	}
 
 	XFreeGC (display, gc);
-	mem_destroy( (ASHashableValue)NULL, m );
+	mem_destroy( (ASHashableValue)(void*)NULL, m );
 	return Success;
 }
 
@@ -830,17 +830,17 @@
 		/* can also be of C_MEM type if we allocated it ourselvs */
 		m = count_find_and_extract (fname, line, (void *)image, C_MEM);
 	if (m)
-		mem_destroy( (ASHashableValue)NULL, m );
+		mem_destroy( (ASHashableValue)(void*)NULL, m );
 
 	/* find and free the image->data pointer if it is in our list */
 	if( image_data )
 		if ((m = count_find_and_extract (fname, line, image_data, C_MEM)) != NULL)
-			mem_destroy( (ASHashableValue)NULL, m );
+			mem_destroy( (ASHashableValue)(void*)NULL, m );
 
 	/* find and free the image->obdata pointer if it is in our list */
 	if( image_obdata )
 		if ((m = count_find_and_extract (fname, line, image_obdata, C_MEM)) != NULL)
-			mem_destroy( (ASHashableValue)NULL, m );
+			mem_destroy( (ASHashableValue)(void*)NULL, m );
 
 	return Success;
 }
@@ -1025,7 +1025,7 @@
 	}
 
 	XFree (data);
-	mem_destroy( (ASHashableValue)NULL, m );
+	mem_destroy( (ASHashableValue)(void*)NULL, m );
 	return Success;
 }
 
