--- bridges/source/cpp_uno/gcc3_linux_x86-64/callvirtualmethod.cxx.orig	2013-08-13 16:11:48.000000000 -0400
+++ bridges/source/cpp_uno/gcc3_linux_x86-64/callvirtualmethod.cxx	2013-09-17 14:52:46.000000000 -0400
@@ -63,11 +63,12 @@
     pMethod = *((sal_uInt64 *)pMethod);
 
     // Load parameters to stack, if necessary
+    sal_uInt64* pCallStack = NULL;
     if ( nStack )
     {
         // 16-bytes aligned
         sal_uInt32 nStackBytes = ( ( nStack + 1 ) >> 1 ) * 16;
-        sal_uInt64 *pCallStack = (sal_uInt64 *) __builtin_alloca( nStackBytes );
+        pCallStack = (sal_uInt64 *) __builtin_alloca( nStackBytes );
         std::memcpy( pCallStack, pStack, nStackBytes );
     }
 
@@ -112,7 +113,8 @@
         "movsd %%xmm0, %2\n\t"
         "movsd %%xmm1, %3\n\t"
         : "=m" ( rax ), "=m" ( rdx ), "=m" ( xmm0 ), "=m" ( xmm1 )
-        : "m" ( pMethod ), "m" ( pGPR ), "m" ( pFPR ), "m" ( nFPR )
+        : "m" ( pMethod ), "m" ( pGPR ), "m" ( pFPR ), "m" ( nFPR ),
+          "m" ( pCallStack ) // dummy input to prevent the compiler from optimizing the alloca out
         : "rax", "rdi", "rsi", "rdx", "rcx", "r8", "r9", "r10", "r11",
           "xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7",
           "xmm8", "xmm9", "xmm10", "xmm11", "xmm12", "xmm13", "xmm14", "xmm15"
