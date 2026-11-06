--- libdrizzle-1.0/libdrizzle/constants.h.orig	2026-11-06 18:08:06 UTC
+++ libdrizzle-1.0/libdrizzle/constants.h
@@ -83,6 +83,12 @@ extern "C" {
 #define DRIZZLE_MAX_SERVER_VERSION_SIZE  32
 #define DRIZZLE_MAX_SERVER_EXTRA_SIZE    32
 #define DRIZZLE_MAX_SCRAMBLE_SIZE        20
+#define DRIZZLE_MAX_AUTH_PLUGIN_SIZE     64
+#define DRIZZLE_MAX_AUTH_RESPONSE_SIZE   512
+#define DRIZZLE_AUTH_PLUGIN_NATIVE       "mysql_native_password"
+#define DRIZZLE_AUTH_PLUGIN_SHA2         "caching_sha2_password"
+#define DRIZZLE_AUTH_PLUGIN_SHA256       "sha256_password"
+#define DRIZZLE_AUTH_PLUGIN_CLEAR        "mysql_clear_password"
 #define DRIZZLE_STATE_STACK_SIZE         8
 #define DRIZZLE_ROW_GROW_SIZE            8192
 #define DRIZZLE_DEFAULT_SOCKET_TIMEOUT   10
@@ -171,7 +177,8 @@ typedef enum
   DRIZZLE_CON_FOUND_ROWS=       (1 << 9),
   DRIZZLE_CON_INTERACTIVE=      (1 << 11),
   DRIZZLE_CON_MULTI_STATEMENTS= (1 << 12),
-  DRIZZLE_CON_AUTH_PLUGIN=      (1 << 13)
+  DRIZZLE_CON_AUTH_PLUGIN=      (1 << 13),
+  DRIZZLE_CON_AUTH_NO_RSA=      (1 << 14)
 } drizzle_con_options_t;
 
 /**
