--- src/shell.c.orig    2011-11-01 16:31:18.000000000 +0400
+++ src/shell.c 2011-11-10 22:45:11.000000000 +0400
@@ -490,7 +490,7 @@
 */
 static void output_hex_blob(FILE *out, const void *pBlob, int nBlob){
   int i;
-  char *zBlob = (char *)pBlob;
+  unsigned char *zBlob = (unsigned char *)pBlob;
   fprintf(out,"X'");
   for(i=0; i<nBlob; i++){ fprintf(out,"%02x",zBlob[i]); }
   fprintf(out,"'");
