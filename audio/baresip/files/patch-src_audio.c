--- src/audio.c.orig	2022-07-01 08:52:02 UTC
+++ src/audio.c
@@ -6,7 +6,7 @@
  */
 #define _DEFAULT_SOURCE 1
 #define _BSD_SOURCE 1
-#define _POSIX_C_SOURCE 199309L
+#define _POSIX_C_SOURCE 200112L
 #include <string.h>
 #include <stdlib.h>
 #ifdef HAVE_UNISTD_H
