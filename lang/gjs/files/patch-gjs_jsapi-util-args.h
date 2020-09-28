--- gjs/jsapi-util-args.h.orig	2020-09-12 19:34:36 UTC
+++ gjs/jsapi-util-args.h
@@ -43,7 +43,7 @@
 #include "gjs/jsapi-util.h"
 #include "gjs/macros.h"
 
-GJS_ALWAYS_INLINE [[nodiscard]] static inline bool check_nullable(
+GJS_ALWAYS_INLINE static inline bool check_nullable(
     const char*& fchar, const char*& fmt_string) {
     if (*fchar != '?')
         return false;
