--- ags/util/ags_id_generator.c.orig	2019-02-11 23:40:12 UTC
+++ ags/util/ags_id_generator.c
@@ -53,7 +53,7 @@ ags_id_generator_create_uuid()
   /* make sure uuid is really unique */
   //FIXME:JK: uncomment me
   //  while(uuid_generate_time_safe(out) != 0);
-  uuid_generate_time_safe(out);
+  uuid_generate_time(out); // uuid_generate_time_safe() is missing in FreeBSD's libuuid.so
   
   /* create a string representation */
   uuid_str = (gchar *) malloc((AGS_ID_GENERATOR_DEFAULT_UUID_LENGTH + 1) * sizeof(gchar));
