--- src/knotholder.cpp.orig	Fri Apr 16 23:02:03 2004
+++ src/knotholder.cpp	Sat Apr 17 01:22:19 2004
@@ -164,7 +164,7 @@
 	} else {
 		SPObject *object = (SPObject *) kh->item;
 		sp_object_invoke_write (object, object->repr, SP_OBJECT_WRITE_EXT);
-		sp_document_done (SP_OBJECT_DOCUMENT (kh->item));
+		sp_document_done (SP_OBJECT_DOCUMENT (object));
 	}
 }
 
