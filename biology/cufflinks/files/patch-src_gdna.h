--- src/gdna.h.orig	2022-07-28 03:14:39 UTC
+++ src/gdna.h
@@ -9,7 +9,7 @@ char* reverseComplement(char* seq, int slen=0);
 
 bool gDnaInit();
 
-byte gdna2bit(char* &nt, int n=4); //pack n bases into a byte (n can be 1..4)
-char g2bit2base(byte v2bit); //convert the 2-bit value into 'A', 'C', 'G' or 'T'
+bytex gdna2bit(char* &nt, int n=4); //pack n bases into a byte (n can be 1..4)
+char g2bit2base(bytex v2bit); //convert the 2-bit value into 'A', 'C', 'G' or 'T'
 
 #endif
