--- jbig2dec.c.orig	2018-09-03 16:39:20 UTC
+++ jbig2dec.c
@@ -40,7 +40,10 @@
 #endif
 
 #include "os_types.h"
-#include "sha1.h"
+#include <sha.h>
+#ifndef SHA1_DIGEST_SIZE
+#	define SHA1_DIGEST_SIZE	20
+#endif
 
 #include "jbig2.h"
 #include "jbig2_priv.h"
