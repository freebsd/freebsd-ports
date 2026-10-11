--- src/core/SkRasterPipeline.h.orig	2026-10-11 14:39:49 UTC
+++ src/core/SkRasterPipeline.h
@@ -26,7 +26,8 @@ struct skcms_TransferFunction;
 struct SkImageInfo;
 struct skcms_TransferFunction;
 
-#if __has_cpp_attribute(clang::musttail) && !defined(__EMSCRIPTEN__) && !defined(SK_CPU_ARM32)
+#if __has_cpp_attribute(clang::musttail) && !defined(__EMSCRIPTEN__) && !defined(SK_CPU_ARM32) && \
+        !defined(SK_CPU_PPC)
     #define SK_HAS_MUSTTAIL 1
 #else
     #define SK_HAS_MUSTTAIL 0
