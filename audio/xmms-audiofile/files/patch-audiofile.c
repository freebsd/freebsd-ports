--- audiofile.c.orig	Thu Sep 12 01:28:40 2002
+++ audiofile.c	Thu Sep 12 01:29:11 2002
@@ -18,7 +18,7 @@
 	Software Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 	MA 02111-1307, USA.
 */
-
+#include <pthread.h>
 #include <config.h>
 
 #include <glib.h>
