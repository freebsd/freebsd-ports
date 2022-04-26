--- tinyfiledialogs.c.orig	2022-03-08 00:31:39 UTC
+++ tinyfiledialogs.c
@@ -47,13 +47,6 @@ Thanks for contributions, bug corrections & thorough t
 - Paul Rouget
 */
 
-
-#ifndef __sun
-#ifndef _POSIX_C_SOURCE
-#define _POSIX_C_SOURCE 2 /* to accept POSIX 2 in old ANSI C standards */
-#endif
-#endif
-
 #if !defined(_WIN32) && ( defined(__GNUC__) || defined(__clang__) )
 #if !defined(_GNU_SOURCE)
  #define _GNU_SOURCE /* used only to resolve symbolic links. Can be commented out */
