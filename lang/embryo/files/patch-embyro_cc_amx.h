--- src/bin/embryo_cc_amx.h.orig	Sun Aug 15 22:58:59 2004
+++ src/bin/embryo_cc_amx.h	Sun Aug 15 22:59:15 2004
@@ -32,10 +32,7 @@
    * here, these types are probably undefined.
    */
 # ifndef HAVE_STDINT_H
-typedef short int   int16_t;
-typedef unsigned short int uint16_t;
-typedef int         int32_t;
-typedef unsigned int uint32_t;
+#include <sys/types.h>
 # endif
 #endif
 
