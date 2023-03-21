--- ./src/test/OpenEXRTest/testDwaCompressorSimd.cpp.orig	2023-03-05 20:23:47 UTC
+++ ./src/test/OpenEXRTest/testDwaCompressorSimd.cpp
@@ -401,7 +401,7 @@ testFloatToHalf()
         }
     }
 
-#ifdef IMF_HAVE_NEON
+#ifdef IMF_HAVE_NEON_AARCH64
     {
         cout << "      convertFloatToHalf64_neon()" << endl;
         for (int iter = 0; iter < numIter; ++iter)
@@ -430,7 +430,7 @@ testFloatToHalf()
             }
         }
     }
-    #endif // IMF_HAVE_NEON
+    #endif // IMF_HAVE_NEON_AARCH64
 }
 
 //
@@ -516,7 +516,7 @@ testFromHalfZigZag()
         } // iter
     }     // f16c
 
-#ifdef IMF_HAVE_NEON
+#ifdef IMF_HAVE_NEON_AARCH64
     {
         const int            numIter = 1000000;
         Rand48               rand48 (0);
@@ -553,7 +553,7 @@ testFromHalfZigZag()
         } // iter
     }     // neon
 
-#endif // IMF_HAVE_NEON
+#endif // IMF_HAVE_NEON_AARCH64
 }
 
 
