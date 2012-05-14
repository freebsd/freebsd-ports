--- src/libpiano/piano.h.orig	2012-05-06 07:33:54.000000000 -0700
+++ src/libpiano/piano.h	2012-05-12 19:42:41.000000000 -0700
@@ -25,6 +25,7 @@
 #define _PIANO_H
 
 #include <stdbool.h>
+#define _GCRYPT_IN_LIBGCRYPT
 #include <gcrypt.h>
 
 /* this is our public API; don't expect this api to be stable as long as
