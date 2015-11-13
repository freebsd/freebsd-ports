--- common/sys/intrinsics.h.orig	2015-09-17 06:11:18 UTC
+++ common/sys/intrinsics.h
@@ -361,6 +361,7 @@ namespace embree
 #endif
   }
   
+#if defined(__X86_64__)
   __forceinline unsigned __bsf(unsigned v) 
   {
 #if defined(__AVX2__) 
@@ -369,6 +370,7 @@ namespace embree
     unsigned r = 0; asm ("bsf %1,%0" : "=r"(r) : "r"(v)); return r;
 #endif
   }
+#endif
   
   __forceinline size_t __bsf(size_t v) {
 #if defined(__AVX2__)
@@ -389,12 +391,14 @@ namespace embree
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
@@ -411,6 +415,7 @@ namespace embree
 #endif
   }
   
+#if defined(__X86_64__)
   __forceinline unsigned __bsr(unsigned v) {
 #if defined(__AVX2__) 
     return 31 - _lzcnt_u32(v);
@@ -418,6 +423,7 @@ namespace embree
     unsigned r = 0; asm ("bsr %1,%0" : "=r"(r) : "r"(v)); return r;
 #endif
   }
+#endif
   
   __forceinline size_t __bsr(size_t v) {
 #if defined(__AVX2__)
@@ -443,7 +449,11 @@ namespace embree
 
   __forceinline size_t __blsr(size_t v) {
 #if defined(__AVX2__) 
-    return _blsr_u64(v);
+#if defined(__X86_64__)
+    return __blsr_u64(v);
+#else
+    return __blsr_u32(v);
+#endif
 #else
     return v & (v-1);
 #endif
