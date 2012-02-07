--- src/plugin.cc-dist	2012-01-18 12:40:15.870419356 +0100
+++ src/plugin.cc	2012-01-18 13:28:16.760422152 +0100
@@ -44,6 +44,13 @@
 
 using namespace SooperLooper;
 
+#if __FreeBSD__ >= 2
+#include <osreldate.h>
+#  if __FreeBSD_version < 900500
+   /* not defined before FreeBSD 9 */
+#  define log2(x)        (log(x) / M_LN2)
+#  endif /* __FreeBSD_version < 900500 */
+#endif /* __FreeBSD__ */ 
 
 /*****************************************************************************/
 //#define LOOPDEBUG
