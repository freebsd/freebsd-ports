--- kioslaves/mbox/readmbox.cc.orig	Sun Dec 18 15:43:49 2005
+++ kioslaves/mbox/readmbox.cc	Sun Dec 18 15:58:15 2005
@@ -16,6 +16,8 @@
  * License along with this library; if not, write to the Free Software
  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
  */
+#include <config.h>
+
 #include "readmbox.h"
 
 #include "mbox.h"
@@ -28,6 +30,10 @@
 #include <qfileinfo.h>
 #include <qstring.h>
 #include <qtextstream.h>
+
+#ifdef HAVE_SYS_TYPES_H
+#include <sys/types.h>
+#endif
 
 #include <utime.h>
 
