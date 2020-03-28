--- jbig2dec.c.orig	2020-02-11 16:28:00 UTC
+++ jbig2dec.c
@@ -33,7 +33,10 @@
 #endif
 
 #include "os_types.h"
-#include "sha1.h"
+#include <sha.h>
+#ifndef SHA1_DIGEST_SIZE
+#	define SHA1_DIGEST_SIZE	20
+#endif
 
 #ifdef JBIG_EXTERNAL_MEMENTO_H
 #include JBIG_EXTERNAL_MEMENTO_H
