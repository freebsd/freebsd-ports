--- src/sockwrap/sockwrap.cpp.orig
+++ src/sockwrap/sockwrap.cpp
@@ -16,6 +16,8 @@
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
 
+#include <unistd.h>
+
 #include "sockwrap.h"
 #include "sockwrap_plain.h"
 #ifdef HAVE_TLS
