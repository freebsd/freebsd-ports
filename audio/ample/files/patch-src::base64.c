--- src/base64.c.orig	Tue Nov 25 18:28:56 2003
+++ src/base64.c	Sat Jul  3 22:38:53 2004
@@ -18,6 +18,8 @@
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  */
 
+#include <config.h>
+
 #include <stdlib.h>
 #include <string.h>
 #ifdef HAVE_SYS_TYPES_H
