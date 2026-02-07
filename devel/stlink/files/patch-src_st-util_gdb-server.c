--- src/st-util/gdb-server.c.orig	2025-04-02 12:39:38 UTC
+++ src/st-util/gdb-server.c
@@ -1041,7 +1041,7 @@ int32_t serve(stlink_t *sl, st_state_t *st) {
                     params = separator + 1;
                 }
 
-                uint32_t hex_len = strlen(params);
+                uint32_t hex_len = (uint32_t) strlen(params);
                 uint32_t alloc_size = (hex_len / 2) + 1;
                 uint32_t cmd_len;
                 char *cmd = malloc(alloc_size);
