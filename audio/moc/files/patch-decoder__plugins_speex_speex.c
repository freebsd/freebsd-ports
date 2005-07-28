--- decoder_plugins/speex/speex.c.orig	Fri Jul 29 01:34:35 2005
+++ decoder_plugins/speex/speex.c	Fri Jul 29 01:34:45 2005
@@ -17,7 +17,7 @@
 #endif
 
 #include <string.h>
-#include <stdint.h>
+#include <inttypes.h>
 #include <assert.h>
 #include <speex/speex.h>
 #include <speex/speex_header.h>
