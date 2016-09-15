Apply patch


Patch attached with submission follows:

--- src/cache.c.orig	2005-02-04 10:24:55 UTC
+++ src/cache.c
@@ -364,7 +364,7 @@ int setup_fileinfo(sstr * filename)
 	int code;
 	sstr *msg;
 
-	if(!strcasecmp(config.cachemod, "Local") || !config.forcehttp) {
+	if(!strcasecmp(config.cachemod, "Local") || config.forcehttp) {
 		send_ccommand("SIZE", sstr_buf(filename));
 		get_message(&code, &msg);
 		if(code / 100 != 2) {
