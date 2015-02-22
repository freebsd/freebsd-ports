--- tools/gcttool/main.c.orig	2010-06-24 17:11:37.000000000 +0200
+++ tools/gcttool/main.c	2015-02-22 16:38:40.511814536 +0100
@@ -48,14 +48,14 @@
 			      const char *password,
 			      unsigned char *buffer,
 			      unsigned int bsize) {
-  des_cblock left, right;
+  DES_cblock left, right;
   int i;
 
   if (bsize!=16) {
     DBG_ERROR(GWEN_LOGDOMAIN, "Buffer must be exact 16 bytes in length");
     return -1;
   }
-  des_string_to_2keys(password, &left, &right);
+  DES_string_to_2keys(password, &left, &right);
   for (i=0; i<8; i++)
     *(buffer++)=left[i];
   for (i=0; i<8; i++)
