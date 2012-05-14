--- src/libpiano/crypt.c.orig	2012-05-06 07:33:54.000000000 -0700
+++ src/libpiano/crypt.c	2012-05-12 19:42:13.000000000 -0700
@@ -23,6 +23,7 @@
 
 #include <string.h>
 #include <assert.h>
+#define _GCRYPT_IN_LIBGCRYPT
 #include <gcrypt.h>
 #include <stdio.h>
 #include <stdlib.h>
