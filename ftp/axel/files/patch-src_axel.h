- workaround for https://github.com/axel-download-accelerator/axel/issues/399

--- src/axel.h.orig	2023-01-22 20:28:34 UTC
+++ src/axel.h
@@ -101,7 +101,7 @@ typedef struct {
 } message_t;
 
 typedef message_t url_t;
-typedef message_t if_t;
+typedef message_t if_t_;
 
 #include "abuf.h"
 #include "conf.h"
