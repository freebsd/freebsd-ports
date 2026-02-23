--- host/utilities/bladeRF-cli/src/cmd/flash_image.c.orig	2025-10-06 23:06:05 UTC
+++ host/utilities/bladeRF-cli/src/cmd/flash_image.c
@@ -68,7 +68,7 @@ static int handle_param(const char *param, char *val,
             status = CLI_RET_INVPARAM;
         } else {
             for (i = 0; i < len && status == 0; i++) {
-                if (val[i] >= 'a' || val[i] <= 'f') {
+                if (val[i] >= 'a' && val[i] <= 'f') {
                     val[i] -= 'a' - 'A';
                 } else if (!((val[i] >= '0' && val[i] <= '9') ||
                              (val[i] >= 'A' && val[i] <= 'F'))) {
