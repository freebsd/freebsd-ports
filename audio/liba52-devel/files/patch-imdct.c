--- imdct.c.orig	Sun Aug 24 10:57:20 2003
+++ imdct.c	Sun Dec 11 03:24:14 2005
@@ -24,6 +24,12 @@
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  */
 
+#include <math.h>
+
+#ifdef LIBA52_DJBFFT
+#include <djbfft/fftc4.h>
+#endif
+
 #include "a52.h"
 #include "a52_internal.h"
 #include "mm_accel.h"
