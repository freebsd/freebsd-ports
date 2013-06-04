--- flgife.c.orig
+++ flgife.c
@@ -57,6 +57,7 @@
 code available free from MLM@CS.CMU.EDU and from UUNET archives$";
 #endif
 
+void compress( int init_bits, FILE *outfile, ifunptr ReadValue );
 
 /*
  * Bump the 'curx' and 'cury' to point to the next pixel
