--- libdrizzle/field.cc.orig	2018-08-27 19:29:52 UTC
+++ libdrizzle/field.cc
@@ -239,7 +239,7 @@ drizzle_return_t drizzle_state_field_read(drizzle_st *
     }
 
     drizzle_log_debug(con,
-                      "field_offset= %"PRIu64", field_size= %zu, field_total= %"PRIu64,
+                      "field_offset= %" PRIu64 ", field_size= %zu, field_total= %" PRIu64,
                       con->result->field_offset, con->result->field_size,
                       con->result->field_total);
 
@@ -295,7 +295,7 @@ drizzle_return_t drizzle_state_field_read(drizzle_st *
   con->packet_size-= con->result->field_size;
 
   drizzle_log_debug(con,
-                    "field_offset= %"PRIu64", field_size= %zu, field_total= %"PRIu64,
+                    "field_offset= %" PRIu64 ", field_size= %zu, field_total= %" PRIu64,
                     con->result->field_offset, con->result->field_size,
                     con->result->field_total);
 
