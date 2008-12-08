Apply patch


Patch attached with submission follows:

--- src/cache.c.orig	2008-03-12 16:56:10.000000000 +0200
+++ src/cache.c	2008-03-12 16:56:10.000000000 +0200
@@ -364,7 +364,7 @@
 	int code;
 	sstr *msg;
 
-	if(!strcasecmp(config.cachemod, "Local") || !config.forcehttp) {
+	if(!strcasecmp(config.cachemod, "Local") || config.forcehttp) {
 		send_ccommand("SIZE", sstr_buf(filename));
 		get_message(&code, &msg);
 		if(code / 100 != 2) {


