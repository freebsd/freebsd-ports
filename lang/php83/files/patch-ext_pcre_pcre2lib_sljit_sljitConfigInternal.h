--- ext/pcre/pcre2lib/sljit/sljitConfigInternal.h.orig	2022-08-02 13:57:03 UTC
+++ ext/pcre/pcre2lib/sljit/sljitConfigInternal.h
@@ -303,7 +303,7 @@ extern "C" {
 /* Type of public API functions. */
 /*********************************/
 
-#ifndef SLJIT_API_FUNC_ATTRIBUTE 
+#ifndef SLJIT_API_FUNC_ATTRIBUTE
 #if (defined SLJIT_CONFIG_STATIC && SLJIT_CONFIG_STATIC)
 /* Static ABI functions. For all-in-one programs. */
 
@@ -333,7 +333,7 @@ extern "C" {
  * beware APPLE is known to have removed the code in iOS so
  * it will need to be excempted or result in broken builds
  */
-#if (!defined SLJIT_CACHE_FLUSH && defined __has_builtin)
+#if (!defined SLJIT_CACHE_FLUSH && defined __has_builtin && !defined SLJIT_CONFIG_PPC_32)
 #if __has_builtin(__builtin___clear_cache) && !defined(__clang__)
 
 /*
