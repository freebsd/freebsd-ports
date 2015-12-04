--- jbig2dec.c.orig	2014-10-31 13:30:04 UTC
+++ jbig2dec.c
@@ -41,7 +41,10 @@
 #endif
 
 #include "os_types.h"
-#include "sha1.h"
+#include <sha.h>
+#ifndef SHA1_DIGEST_SIZE
+#	define SHA1_DIGEST_SIZE	20
+#endif
 
 #include "jbig2.h"
 #include "jbig2_priv.h"
