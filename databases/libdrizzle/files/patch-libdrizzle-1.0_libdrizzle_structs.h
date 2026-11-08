--- libdrizzle-1.0/libdrizzle/structs.h.orig	2026-11-06 18:08:06 UTC
+++ libdrizzle-1.0/libdrizzle/structs.h
@@ -148,6 +148,10 @@ struct drizzle_con_st
   char db[DRIZZLE_MAX_DB_SIZE];
   char password[DRIZZLE_MAX_PASSWORD_SIZE];
   uint8_t scramble_buffer[DRIZZLE_MAX_SCRAMBLE_SIZE];
+  uint32_t server_capabilities;
+  char auth_plugin[DRIZZLE_MAX_AUTH_PLUGIN_SIZE];
+  size_t auth_response_size;
+  uint8_t auth_response[DRIZZLE_MAX_AUTH_RESPONSE_SIZE];
   char server_version[DRIZZLE_MAX_SERVER_VERSION_SIZE];
   char server_extra[DRIZZLE_MAX_SERVER_EXTRA_SIZE];
   drizzle_state_fn *state_stack[DRIZZLE_STATE_STACK_SIZE];
