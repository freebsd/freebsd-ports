--- include/util/string.h.orig	2026-06-10 14:00:48 UTC
+++ include/util/string.h
@@ -22,7 +22,6 @@
 #pragma once
 
 #include <assert.h>
-#include <endian.h>
 #include <limits.h>
 #include <stdarg.h>
 #include <stdbool.h>
@@ -46,14 +45,10 @@ struct string {
 ///   * To allow static initialization of non-empty strings.
 ///
 struct string {
-#if BYTE_ORDER == LITTLE_ENDIAN
     /// Length of string. Agrees with strlen().
     size_t len:(CHAR_BIT * sizeof(size_t) - 1);
 
     bool is_short:1;
-#else
-#   error untested endianness
-#endif
 
     union {
         /// If the string is "short", then short_buf::data holds
