--- SuffixArrayFuns.cpp.orig	2021-11-26 18:14:36 UTC
+++ SuffixArrayFuns.cpp
@@ -15,7 +15,7 @@ uint compareSeqToGenome(Genome &mapGen, char** s2, uin
      * dirR forward or reverse direction search on read sequence
      */
 
-    register int64 ii;
+    int64 ii;
 
     uint SAstr=mapGen.SA[iSA];
     bool dirG = (SAstr>>mapGen.GstrandBit) == 0; //forward or reverse strand of the genome
@@ -231,7 +231,7 @@ uint compareSeqToGenome1(Genome &mapGen, char** s2, ui
 
     //TODO no need for complementary sequence
 
-    register int64 ii;
+    int64 ii;
 
     uint SAstr=mapGen.SA[iSA];
     bool dirG = (SAstr>>mapGen.GstrandBit) == 0; //forward or reverse strand of the genome
@@ -356,13 +356,13 @@ uint funCalcSAiFromSA(char* gSeq, PackedArray& gSA, Ge
     bool dirG = (SAstr>>mapGen.GstrandBit) == 0; //forward or reverse strand of the genome
     SAstr &= mapGen.GstrandMask;
     iL4=-1;
-    register uint saind=0;
+    uint saind=0;
     if (dirG)
     {
-        register uint128 g1=*( (uint128*) (gSeq+SAstr) );
+        uint128 g1=*( (uint128*) (gSeq+SAstr) );
         for (int ii=0; ii<L; ii++)
         {
-            register char g2=(char) g1;
+            char g2=(char) g1;
             if (g2>3)
             {
                 iL4=ii;
@@ -376,10 +376,10 @@ uint funCalcSAiFromSA(char* gSeq, PackedArray& gSA, Ge
         return saind;
     } else
     {
-        register uint128 g1=*( (uint128*) (gSeq+mapGen.nGenome-SAstr-16) );
+        uint128 g1=*( (uint128*) (gSeq+mapGen.nGenome-SAstr-16) );
         for (int ii=0; ii<L; ii++)
         {
-            register char g2=(char) (g1>>(8*(15-ii)));
+            char g2=(char) (g1>>(8*(15-ii)));
             if (g2>3)
             {
                 iL4=ii;
