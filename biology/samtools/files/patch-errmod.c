--- errmod.c.orig	2015-12-15 21:26:20 UTC
+++ errmod.c
@@ -24,6 +24,13 @@ FROM, OUT OF OR IN CONNECTION WITH THE S
 DEALINGS IN THE SOFTWARE.  */
 
 #include <math.h>
+
+#include <sys/param.h>
+#if defined(__FreeBSD__) && (__FreeBSD_version < 1000034)
+#	define logl(x) log(x)
+#	define expl(x) exp(x)
+#endif
+
 #include "errmod.h"
 #include "htslib/ksort.h"
 KSORT_INIT_GENERIC(uint16_t)
