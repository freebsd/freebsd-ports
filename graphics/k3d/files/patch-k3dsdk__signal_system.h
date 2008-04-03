--- k3dsdk/signal_system.h.orig	2008-04-02 23:05:41.000000000 -0500
+++ k3dsdk/signal_system.h	2008-04-02 23:06:05.000000000 -0500
@@ -20,10 +20,7 @@
 // License along with this program; if not, write to the Free Software
 // Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 
-#include <sigc++/bind.h>
-#include <sigc++/connection.h>
-#include <sigc++/hide.h>
-#include <sigc++/signal.h>
+#include <sigc++/sigc++.h>
 
 #endif // !K3DSDK_SIGNAL_SYSTEM_H
 
