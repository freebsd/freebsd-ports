--- ./src/lib/OpenEXR/ImfDwaCompressor.cpp.orig	2023-03-05 20:23:47 UTC
+++ ./src/lib/OpenEXR/ImfDwaCompressor.cpp
@@ -2888,7 +2888,7 @@ DwaCompressor::initializeFuncs()
         fromHalfZigZag       = fromHalfZigZag_f16c;
     } 
 
-#ifdef IMF_HAVE_NEON
+#ifdef IMF_HAVE_NEON_AARCH64
     {
         convertFloatToHalf64 = convertFloatToHalf64_neon;
         fromHalfZigZag       = fromHalfZigZag_neon;
