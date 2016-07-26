--- src/base64.c.orig	2003-11-25 09:28:56 UTC
+++ src/base64.c
@@ -18,6 +18,8 @@
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  */
 
+#include <config.h>
+
 #include <stdlib.h>
 #include <string.h>
 #ifdef HAVE_SYS_TYPES_H
