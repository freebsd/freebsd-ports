--- deps/sljit/sljit_src/sljitConfigInternal.h.orig	2025-02-06 07:15:34 UTC
+++ deps/sljit/sljit_src/sljitConfigInternal.h
@@ -255,7 +255,7 @@ extern "C" {
  * system provided method that should be defined below is used
  * instead.
  */
-#if (!defined SLJIT_CACHE_FLUSH && defined __has_builtin)
+#if (!defined SLJIT_CACHE_FLUSH && defined __has_builtin && !defined SLJIT_CONFIG_PPC_32)
 #if __has_builtin(__builtin___clear_cache) && !defined(__clang__)
 
 /*
