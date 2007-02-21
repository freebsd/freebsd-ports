--- src/pxconvert.c.orig	Wed Feb 21 19:48:42 2007
+++ src/pxconvert.c	Wed Feb 21 19:49:51 2007
@@ -512,7 +512,12 @@
 #ifdef DEBUG	
 	fprintf(stderr, "[BLOB] offset: %08lx, length: %08lx, mod_number: %04x, index: %02x\n", offset, length, mod_number, index);
 #endif
-	if (index == 0x00) return 0;
+
+       if (index == 0x00) {
+       *binsize = 0;
+       *binstorage = NULL;
+       return 0;
+       }
 	
 	if (!blobname) {
 		fprintf(stderr, "[BLOB] offset: %08lx, length: %08lx, mod_number: %04x, index: %02x - do I need a BLOB-filename '-b ...' ?\n", offset, length, mod_number, index);
