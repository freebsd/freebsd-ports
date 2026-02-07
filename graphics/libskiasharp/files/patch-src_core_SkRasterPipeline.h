--- src/core/SkRasterPipeline.h.orig	2025-11-18 06:35:10 UTC
+++ src/core/SkRasterPipeline.h
@@ -24,7 +24,7 @@ struct skcms_TransferFunction;
 struct SkImageInfo;
 struct skcms_TransferFunction;
 
-#if __has_cpp_attribute(clang::musttail) && !defined(__EMSCRIPTEN__) && !defined(SK_CPU_ARM32)
+#if __has_cpp_attribute(clang::musttail) && !defined(__EMSCRIPTEN__) && !defined(SK_CPU_ARM32) && !defined(__powerpc__)
     #define SK_HAS_MUSTTAIL 1
 #else
     #define SK_HAS_MUSTTAIL 0
