--- prob1.c.orig	2015-04-28 01:28:23 UTC
+++ prob1.c
@@ -33,6 +33,14 @@ THE SOFTWARE.  */
 #include <zlib.h>
 #include "prob1.h"
 
+#include <sys/param.h>
+#ifdef __FreeBSD__
+#	if __FreeBSD_version < 1000034
+#		define logl(x) log(x)
+#		define expl(x) exp(x)
+#	endif
+#endif
+
 // #include "kstring.h"
 // #include "kseq.h"
 // KSTREAM_INIT(gzFile, gzread, 16384)
