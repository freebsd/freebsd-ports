--- xpdf/gpdf-thumbnails-view.cc.orig	Wed Jan 14 00:09:05 2004
+++ xpdf/gpdf-thumbnails-view.cc	Wed Jan 14 00:09:34 2004
@@ -21,6 +21,7 @@
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.
  */
 
+#include <sys/types.h>
 #include <gpdf-g-switch.h>
 #  include <glib.h>
 #  include <glib/ghash.h>
