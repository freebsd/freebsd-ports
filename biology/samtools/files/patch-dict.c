--- dict.c.orig	2015-12-15 21:26:20 UTC
+++ dict.c
@@ -25,6 +25,7 @@ DEALINGS IN THE SOFTWARE.  */
 #include <stdio.h>
 #include <zlib.h>
 #include <getopt.h>
+#include <unistd.h>
 #include "htslib/kseq.h"
 #include "htslib/hts.h"
 
