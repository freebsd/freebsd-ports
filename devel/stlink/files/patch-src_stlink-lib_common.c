--- src/stlink-lib/common.c.orig	2025-04-02 12:21:51 UTC
+++ src/stlink-lib/common.c
@@ -913,7 +913,7 @@ int32_t stlink_parse_ihex(const char *path, uint8_t er
         break;
       }
 
-      uint32_t l = strlen(line);
+      size_t l = strlen(line);
 
       while (l > 0 && (line[l - 1] == '\n' || line[l - 1] == '\r')) {
         --l;
