--- external/src/blosc/shuffle.cc.orig	2020-07-31 17:44:09 UTC
+++ external/src/blosc/shuffle.cc
@@ -158,6 +158,8 @@ __cpuidex(int32_t cpuInfo[4], int32_t function_id, int
 /* Reads the content of an extended control register.
    https://software.intel.com/en-us/articles/how-to-detect-new-instruction-support-in-the-4th-generation-intel-core-processor-family
 */
+
+#if defined(__clang_major__) && __clang_major__ < 9
 static inline uint64_t
 _xgetbv(uint32_t xcr) {
   uint32_t eax, edx;
@@ -173,6 +175,7 @@ _xgetbv(uint32_t xcr) {
     );
   return ((uint64_t)edx << 32) | eax;
 }
+#endif
 
 #endif /* defined(_MSC_FULL_VER) */
 
@@ -385,4 +388,4 @@ unshuffle(const size_t bytesoftype, const size_t block
   (host_implementation.unshuffle)(bytesoftype, blocksize, _src, _dest);
 }
 
-}
\ No newline at end of file
+}
