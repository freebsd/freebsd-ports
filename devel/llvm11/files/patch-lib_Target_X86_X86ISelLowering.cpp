--- lib/Target/X86/X86ISelLowering.cpp.orig
+++ lib/Target/X86/X86ISelLowering.cpp
@@ -36201,7 +36201,11 @@
          (RootVT.is128BitVector() && Subtarget.hasVLX())) &&
         (MaskEltSizeInBits > 8 || Subtarget.hasBWI()) &&
         isSequentialOrUndefInRange(Mask, 0, NumMaskElts, 0, 2)) {
-      if (Depth == 0 && Root.getOpcode() == ISD::TRUNCATE)
+      // Bail if this was already a truncation or PACK node.
+      // We sometimes fail to match PACK if we demand known undef elements.
+      if (Depth == 0 && (Root.getOpcode() == ISD::TRUNCATE ||
+                         Root.getOpcode() == X86ISD::PACKSS ||
+                         Root.getOpcode() == X86ISD::PACKUS))
         return SDValue(); // Nothing to do!
       ShuffleSrcVT = MVT::getIntegerVT(MaskEltSizeInBits * 2);
       ShuffleSrcVT = MVT::getVectorVT(ShuffleSrcVT, NumMaskElts / 2);
