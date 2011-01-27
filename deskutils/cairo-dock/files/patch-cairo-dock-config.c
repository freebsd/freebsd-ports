--- ./src/gldit/cairo-dock-config.c.orig	2010-10-02 01:41:55.000000000 +0300
+++ ./src/gldit/cairo-dock-config.c	2010-12-11 02:06:06.000000000 +0200
@@ -27,8 +27,6 @@
 
 #include "../config.h"
 #ifdef HAVE_LIBCRYPT
-/* libC crypt */
-#include <crypt.h>
 
 static char DES_crypt_key[64] =
 {
