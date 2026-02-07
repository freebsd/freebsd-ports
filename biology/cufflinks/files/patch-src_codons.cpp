--- src/codons.cpp.orig	2022-07-28 03:23:12 UTC
+++ src/codons.cpp
@@ -48,9 +48,9 @@ static bool isCodonTableReady=codonTableInit();
 
 unsigned short packCodon(char n1, char n2, char n3) {
  //assumes they are uppercase already!
- byte b1=n1-'A';
- byte b2=n2-'A';
- byte b3=n3-'A';
+ bytex b1=n1-'A';
+ bytex b2=n2-'A';
+ bytex b3=n3-'A';
  b1 |= (b2 << 5); 
  b2 = (b2 >> 3) | (b3 << 2);
  return ( ((unsigned short)b2) << 8) + b1;
@@ -68,7 +68,7 @@ bool codonTableInit() {
 
 
 char Codon::translate() {
- for (byte i=0;i<3;i++) nuc[i]=toupper(nuc[i]);
+ for (bytex i=0;i<3;i++) nuc[i]=toupper(nuc[i]);
  unsigned short aacode=packCodon(nuc[0], nuc[1], nuc[2]);
  return codonTable[aacode];
  }
