--- ext/pcre/pcre2lib/sljit/sljitConfigInternal.h.orig	2023-12-20 12:44:38 UTC
+++ ext/pcre/pcre2lib/sljit/sljitConfigInternal.h
@@ -308,7 +308,7 @@ extern "C" {
 /* Type of public API functions. */
 /*********************************/
 
-#ifndef SLJIT_API_FUNC_ATTRIBUTE 
+#ifndef SLJIT_API_FUNC_ATTRIBUTE
 #if (defined SLJIT_CONFIG_STATIC && SLJIT_CONFIG_STATIC)
 /* Static ABI functions. For all-in-one programs. */
 
@@ -344,7 +344,7 @@ extern "C" {
  * system provided method that should be defined below is used
  * instead.
  */
-#if (!defined SLJIT_CACHE_FLUSH && defined __has_builtin)
+#if (!defined SLJIT_CACHE_FLUSH && defined __has_builtin && !defined SLJIT_CONFIG_PPC_32)
 #if __has_builtin(__builtin___clear_cache) && !defined(__clang__)
 
 /*
