--- common/sys/intrinsics.h.orig	2016-05-20 05:45:13 UTC
+++ common/sys/intrinsics.h
@@ -268,6 +268,7 @@ namespace embree
 #endif
   }
   
+#if defined(__X86_64__)
   __forceinline unsigned __bsf(unsigned v) 
   {
 #if defined(__AVX2__) 
@@ -276,6 +277,7 @@ namespace embree
     unsigned r = 0; asm ("bsf %1,%0" : "=r"(r) : "r"(v)); return r;
 #endif
   }
+#endif
   
   __forceinline size_t __bsf(size_t v) {
 #if defined(__AVX2__)
@@ -306,12 +308,14 @@ namespace embree
     return i;
   }
   
+#if defined(__X86_64__)
   __forceinline unsigned int __bscf(unsigned int& v) 
   {
     unsigned int i = __bsf(v);
     v &= v-1;
     return i;
   }
+#endif
   
   __forceinline size_t __bscf(size_t& v) 
   {
@@ -328,6 +332,7 @@ namespace embree
 #endif
   }
   
+#if defined(__X86_64__)
   __forceinline unsigned __bsr(unsigned v) {
 #if defined(__AVX2__) 
     return 31 - _lzcnt_u32(v);
@@ -335,6 +340,7 @@ namespace embree
     unsigned r = 0; asm ("bsr %1,%0" : "=r"(r) : "r"(v)); return r;
 #endif
   }
+#endif
   
   __forceinline size_t __bsr(size_t v) {
 #if defined(__AVX2__)
@@ -363,7 +369,11 @@ namespace embree
 #if defined(__INTEL_COMPILER)
     return _blsr_u64(v);
 #else
+#if defined(__X86_64__)
     return __blsr_u64(v);
+#else
+    return __blsr_u32(v);
+#endif
 #endif
 #else
     return v & (v-1);
