--- src/sljit/sljitConfigInternal.h.orig	2022-05-02 15:22:09 UTC
+++ src/sljit/sljitConfigInternal.h
@@ -333,7 +333,7 @@ extern "C" {
  * beware APPLE is known to have removed the code in iOS so
  * it will need to be excempted or result in broken builds
  */
-#if (!defined SLJIT_CACHE_FLUSH && defined __has_builtin)
+#if (!defined SLJIT_CACHE_FLUSH && defined __has_builtin && !defined SLJIT_CONFIG_PPC_32)
 #if __has_builtin(__builtin___clear_cache) && !defined(__clang__)
 
 /*
