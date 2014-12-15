--- errmod.c.orig	2014-12-15 20:22:22 UTC
+++ errmod.c
@@ -24,6 +24,15 @@ FROM, OUT OF OR IN CONNECTION WITH THE S
 DEALINGS IN THE SOFTWARE.  */
 
 #include <math.h>
+
+#include <sys/param.h>
+#ifdef __FreeBSD__
+#	if __FreeBSD_version < 1000034
+#		define logl(x) log(x)
+#		define expl(x) exp(x)
+#	endif
+#endif
+
 #include "errmod.h"
 #include "htslib/ksort.h"
 KSORT_INIT_GENERIC(uint16_t)
