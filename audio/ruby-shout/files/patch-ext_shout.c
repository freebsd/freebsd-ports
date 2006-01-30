--- ext/shout.c.orig	Mon Jan 30 17:53:08 2006
+++ ext/shout.c	Mon Jan 30 17:54:51 2006
@@ -606,9 +606,10 @@ VALUE _sh_description_eq(VALUE self, VAL
  */
 VALUE _sh_metadata_eq(VALUE self, VALUE meta) {
         int err;
-        shout_connection *s; GET_SC(self, s);
-        shout_metadata_t *m; Data_Get_Struct(meta, shout_metadata_t, m);
-
+        shout_connection *s;
+        shout_metadata_t *m;
+	GET_SC(self, s);
+	Data_Get_Struct(meta, shout_metadata_t, m);
         err = shout_set_metadata(s->conn, m);
 
         if(err != SHOUTERR_SUCCESS) {
