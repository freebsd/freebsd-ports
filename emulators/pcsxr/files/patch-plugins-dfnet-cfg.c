--- plugins/dfnet/cfg.c.orig	2020-09-07 22:26:23 UTC
+++ plugins/dfnet/cfg.c
@@ -13,6 +13,8 @@
 
 #define CFG_FILENAME "dfnet.cfg"
 
+Config conf;
+
 void SaveConf() {
 	FILE *f;
 
