--- ext/pcre/pcre2lib/sljit/sljitConfigInternal.h.orig	2022-03-25 09:54:56 UTC
+++ ext/pcre/pcre2lib/sljit/sljitConfigInternal.h
@@ -283,7 +283,7 @@
 /* Instruction cache flush. */
 /****************************/
 
-#if (!defined SLJIT_CACHE_FLUSH && defined __has_builtin)
+#if (!defined SLJIT_CACHE_FLUSH && defined __has_builtin && !defined SLJIT_CONFIG_PPC_32)
 #if __has_builtin(__builtin___clear_cache)
 
 #define SLJIT_CACHE_FLUSH(from, to) \
