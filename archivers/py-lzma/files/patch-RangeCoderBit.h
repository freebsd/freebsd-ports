--- 7zip/7zip/Compress/LZMA/../RangeCoder/RangeCoderBit.h.orig	Wed Apr 28 07:17:33 2004
+++ 7zip/7zip/Compress/LZMA/../RangeCoder/RangeCoderBit.h	Sat Aug 14 14:30:03 2004
@@ -38,6 +38,8 @@
   UINT32 Probability;
   void UpdateModel(UINT32 symbol)
   {
+#define Probability (this->Probability)
+#define UpdateModel (this->UpdateModel)
     /*
     Probability -= (Probability + ((symbol - 1) & ((1 << aNumMoveBits) - 1))) >> aNumMoveBits;
     Probability += (1 - symbol) << (kNumBitModelTotalBits - aNumMoveBits);
@@ -100,6 +102,8 @@
     }
   }
 };
+#undef Probability
+#undef UpdateModel
 
 }}
 
