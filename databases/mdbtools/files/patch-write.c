--- src/libmdb/write.c	Thu Jan  9 15:24:27 2003
+++ src/libmdb/write.c	Tue Apr  8 16:29:38 2003
@@ -308,3 +308,3 @@
 	}
-	num_fields = mdb_crack_row(table, row_start, row_end, &fields);
+	num_fields = mdb_crack_row(table, row_start, row_end, fields);
 
@@ -324,3 +324,3 @@
 
-	new_row_size = mdb_pack_row(table, row_buffer, num_fields, &fields);
+	new_row_size = mdb_pack_row(table, row_buffer, num_fields, fields);
 #if MDB_DEBUG_WRITE
