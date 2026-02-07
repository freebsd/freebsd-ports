--- src/gdna.cpp.orig	2022-07-28 03:26:30 UTC
+++ src/gdna.cpp
@@ -11,8 +11,8 @@ const char* IUPAC_COMP  ="TtGgAaCcAaKkYyWwSsRrMmBbDdHh
 #define G_2BIT 2 // 10
 #define T_2BIT 3 // 11
 
-static byte ntCompTable[256];
-static byte nt2bit[256]; //maps any character to a 2bit base value (with N = A)
+static bytex ntCompTable[256];
+static bytex nt2bit[256]; //maps any character to a 2bit base value (with N = A)
 static char v_2bit2nt[4] = {'A','C','G','T'};
 
 //----------------------
@@ -21,9 +21,9 @@ static bool gdna_Ready=gDnaInit();
 
 //----------------------
 
-byte gdna2bit(char* &nt, int n) {
+bytex gdna2bit(char* &nt, int n) {
 // Pack n bases into a byte (n can be 1..4)
-byte out = 0;
+bytex out = 0;
 while (n && *nt) {
     n--;
     out <<= 2;
@@ -43,7 +43,7 @@ char ntComplement(char c) {
  return ntCompTable[(int)c];
  }
 
-char g2bit2base(byte v2bit) {
+char g2bit2base(bytex v2bit) {
  return v_2bit2nt[v2bit & 0x03 ];
 }
 
