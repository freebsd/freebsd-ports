--- src/document-subset.cpp.orig	2010-01-17 13:47:18.000000000 +0800
+++ src/document-subset.cpp	2010-01-17 13:49:59.000000000 +0800
@@ -184,9 +184,6 @@
 
     void _doRemove(SPObject *obj) {
         Record &record=records[obj];
-        record.release_connection.disconnect();
-        record.position_changed_connection.disconnect();
-        records.erase(obj);
 
         if ( record.parent == NULL ) {
             Record &root = records[NULL];
@@ -198,6 +195,12 @@
             }
         }
 
+	/* Record must be ereased after removing from root, or
+	 * content of record would be invalided. */
+        record.release_connection.disconnect();
+        record.position_changed_connection.disconnect();
+        records.erase(obj);
+	
         removed_signal.emit(obj);
         sp_object_unref(obj);
     }
