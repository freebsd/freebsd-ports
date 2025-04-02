--- src/stlink-lib/chipid.c.orig	2025-04-02 12:25:21 UTC
+++ src/stlink-lib/chipid.c
@@ -212,7 +212,7 @@ void process_chipfile(char *fname) {
 
 void init_chipids(char *dir_to_scan) {
   DIR *d;
-  uint32_t nl; // namelen
+  size_t nl; // namelen
   struct dirent *dir;
 
   if (!dir_to_scan) {
