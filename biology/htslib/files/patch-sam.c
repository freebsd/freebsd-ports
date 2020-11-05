--- sam.c.orig	2020-10-18 00:50:46 UTC
+++ sam.c
@@ -35,6 +35,7 @@ DEALINGS IN THE SOFTWARE.  */
 #include <assert.h>
 #include <signal.h>
 #include <inttypes.h>
+#include <unistd.h>	// usleep()
 
 // Suppress deprecation message for cigar_tab, which we initialise
 #include "htslib/hts_defs.h"
