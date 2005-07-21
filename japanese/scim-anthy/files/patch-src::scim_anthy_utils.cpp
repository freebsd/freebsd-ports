Index: src/scim_anthy_utils.cpp
diff -u src/scim_anthy_utils.cpp.orig src/scim_anthy_utils.cpp
--- src/scim_anthy_utils.cpp.orig	Thu Jul  7 17:24:45 2005
+++ src/scim_anthy_utils.cpp	Thu Jul 21 16:54:04 2005
@@ -17,6 +17,7 @@
  *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
 
+#include <unistd.h>
 #include <sys/wait.h>
 
 #include "scim_anthy_utils.h"
