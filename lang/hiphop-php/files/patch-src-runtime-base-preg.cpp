--- src/runtime/base/preg.cpp.orig	2012-07-12 15:09:35.645510793 +0200
+++ src/runtime/base/preg.cpp	2012-07-12 15:18:26.056540495 +0200
@@ -126,6 +126,7 @@
 
 static pcre_cache_entry *pcre_get_compiled_regex_cache(CStrRef regex) {
   PCRECache &pcre_cache = *s_pcre_cache;
+  int count = 0;
 
   /* Try to lookup the cached regex entry, and if successful, just pass
      back the compiled pattern, otherwise go on and compile it. */
@@ -135,7 +136,7 @@
      * We use a quick pcre_info() check to see whether cache is corrupted,
      * and if it is, we flush it and compile the pattern from scratch.
      */
-    if (pcre_info(pce->re, NULL, NULL) == PCRE_ERROR_BADMAGIC) {
+    if (pcre_fullinfo(pce->re, NULL, PCRE_INFO_CAPTURECOUNT, &count) == PCRE_ERROR_BADMAGIC) {
       pcre_cache.cleanup();
     } else {
 #if HAVE_SETLOCALE
