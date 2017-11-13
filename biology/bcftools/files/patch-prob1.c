--- prob1.c.orig	2017-09-28 11:22:48 UTC
+++ prob1.c
@@ -33,6 +33,12 @@ THE SOFTWARE.  */
 #include <zlib.h>
 #include "prob1.h"
 
+#include <sys/param.h>
+#if defined(__FreeBSD__) && (__FreeBSD_version < 1000034)
+#	define logl(x) log(x)
+#	define expl(x) exp(x)
+#endif
+
 // #include "kstring.h"
 // #include "kseq.h"
 // KSTREAM_INIT(gzFile, gzread, 16384)
