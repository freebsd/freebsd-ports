--- src/libgutenfetch_detail.c.orig	Sat Jul  3 21:06:50 2004
+++ src/libgutenfetch_detail.c	Tue Jul 20 15:19:40 2004
@@ -92,10 +92,12 @@
 int
 directory_data_compare(const void *a, const void *b, void *param)
 {
+	directory_data_t *da;
+	directory_data_t *db;
 	assert( a != NULL );
 	assert( b != NULL );
-	directory_data_t *da = (directory_data_t*)a;
-	directory_data_t *db = (directory_data_t*)b;
+	da = (directory_data_t*)a;
+	db = (directory_data_t*)b;
 	return strcmp(da->directory, db->directory);
 }
 
