--- Namazu.xs.orig     Fri Jun  2 21:58:37 2006
+++ Namazu.xs  Fri Jun  2 21:59:07 2006
@@ -46,6 +46,15 @@
 }
 #endif

+/* try to be compatible with older perls */
+/* SvPV_nolen() macro first defined in 5.005_55 */
+/* this is slow, not threadsafe, but works */
+#include "patchlevel.h"
+#if (PATCHLEVEL == 4) || ((PATCHLEVEL == 5) && (SUBVERSION < 55))
+static STRLEN nolen_na;
+# define SvPV_nolen(sv) SvPV ((sv), nolen_na)
+#endif
+
 /* for old perl (< 5.004_04?) */
 #if !defined(PL_na) && defined(na)
 #define PL_na na
