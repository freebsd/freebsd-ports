https://github.com/AcademySoftwareFoundation/openexr/pull/1507/files
      
--- src/lib/OpenEXRCore/internal_cpuid.h.orig	2023-07-31 18:17:50 UTC
+++ src/lib/OpenEXRCore/internal_cpuid.h
@@ -39,14 +39,16 @@ static inline void check_for_x86_simd (int *f16c, int 
     *f16c = 0;
 #    endif
 
-#elif OPENEXR_ENABLE_X86_SIMD_CHECK
+#elif defined(__AVX__) && defined(__F16C__)
 
     // shortcut if everything is turned on / compiled in
-#    if defined(__AVX__) && defined(__F16C__)
     *f16c = 1;
     *avx = 1;
     *sse2 = 1;
-#    elif defined(_MSC_VER) && defined(_WIN32)
+
+#elif OPENEXR_ENABLE_X86_SIMD_CHECK
+
+#   if defined(_MSC_VER) && defined(_WIN32)
     int regs[4], osxsave;
 
     __cpuid (regs, 0);
