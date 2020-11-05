--- hts.c.orig	2020-10-18 00:49:42 UTC
+++ hts.c
@@ -39,6 +39,7 @@ DEALINGS IN THE SOFTWARE.  */
 #include <time.h>
 #include <sys/stat.h>
 #include <assert.h>
+#include <unistd.h>	// R_OK
 
 #include "htslib/hts.h"
 #include "htslib/bgzf.h"
