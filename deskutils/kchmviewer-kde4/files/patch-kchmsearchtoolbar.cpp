--- src/kchmsearchtoolbar.cpp.orig	Sun Dec 11 20:04:40 2005
+++ src/kchmsearchtoolbar.cpp	Sun Dec 11 20:06:22 2005
@@ -19,6 +19,9 @@
  *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
  ***************************************************************************/
 
+#include <sys/types.h>
+#include <unistd.h>
+
 #include <qtoolbutton.h>
 #include <qcombobox.h>
 #include <qlineedit.h>
