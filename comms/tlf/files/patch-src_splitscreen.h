--- src/splitscreen.h.orig	Sat Jul 10 21:29:22 2004
+++ src/splitscreen.h	Sat Jul 10 21:29:42 2004
@@ -17,7 +17,7 @@
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
  // splitscreen.h
-
+#include <sys/types.h>
 #include <curses.h>
 #include "sockserv.h"
 #include <errno.h>
