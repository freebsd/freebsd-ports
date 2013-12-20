--- src/im/request.cpp.orig
+++ src/im/request.cpp
@@ -16,8 +16,9 @@
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
 
-#include <errno.h>
-#include <string.h>
+#include <cerrno>
+#include <cstring>
+#include <unistd.h>
 
 #include "request.h"
 #include "buddy.h"
