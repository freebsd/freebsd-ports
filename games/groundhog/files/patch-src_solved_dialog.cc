--- src/solved_dialog.cc.orig	Sun Oct 30 00:54:28 2005
+++ src/solved_dialog.cc	Sun Oct 30 00:54:56 2005
@@ -16,7 +16,9 @@
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
 
-#include <strstream.h>
+#include <sstream>
+#include <string>
+using namespace std;
 
 #include "intl.h"
 #include "solved_dialog.h"
@@ -33,9 +35,8 @@
 void
 SolvedDialog::SetLabel(int moves)
 {
-   char info[128];
-   std::ostrstream ost(info, sizeof(info));
-
-   ost << _(" Game solved in ") << moves << _(" moves!") << std::ends;
-   gtk_label_set(GTK_LABEL(_label), info);
+   ostringstream ost;
+   ost << _(" Game solved in ") << moves << _(" moves!") << ends;
+   string info = ost.str();
+   gtk_label_set(GTK_LABEL(_label), info.c_str());
 }
