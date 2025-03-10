--- tinyfiledialogs.c.orig	2024-10-14 12:36:00 UTC
+++ tinyfiledialogs.c
@@ -53,13 +53,6 @@ misrepresented as being the original software.
     |__________________________________________|
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
