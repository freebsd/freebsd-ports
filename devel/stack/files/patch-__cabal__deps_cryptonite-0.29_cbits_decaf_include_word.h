https://github.com/haskell-crypto/cryptonite/issues/350

--- _cabal_deps/cryptonite-0.30/cbits/decaf/include/word.h.orig	2019-09-08 00:46:48 UTC
+++ _cabal_deps/cryptonite-0.30/cbits/decaf/include/word.h
@@ -238,7 +238,7 @@ malloc_vector(size_t size) {
 /* PERF: vectorize vs unroll */
 #ifdef __clang__
 #if 100*__clang_major__ + __clang_minor__ > 305
-#define UNROLL _Pragma("clang loop unroll(full)")
+//#define UNROLL _Pragma("clang loop unroll(full)")
 #endif
 #endif
 
