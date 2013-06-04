--- flgifc.c.orig
+++ flgifc.c
@@ -168,10 +168,7 @@
 code available free from MLM@CS.CMU.EDU and from UUNET archives$";
 #endif
 
-compress( init_bits, outfile, ReadValue )
-int init_bits;
-FILE *outfile;
-ifunptr ReadValue;
+void compress( int init_bits, FILE *outfile, ifunptr ReadValue )
 {
     register long fcode;
     register code_int i = 0;
