
$FreeBSD$

--- src/System/Link/pipe_link.cpp.orig	Thu Jul 31 15:26:38 2003
+++ src/System/Link/pipe_link.cpp	Wed Aug 27 20:35:15 2003
@@ -10,6 +10,8 @@
 * 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 ******************************************************************************/
 
+#include <osreldate.h>
+
 #include "pipe_link.hpp"
 #include "sys_utils.hpp"
 #include "hashset.hpp"
@@ -20,8 +22,12 @@
 #include <unistd.h>
 #include <signal.h>
 #include <sys/wait.h>
+#if __FreeBSD_version < 500000
 #ifndef __APPLE__
 #include <malloc.h>
+#endif
+#else
+#include <stdlib.h>
 #endif
 
 hashset<pointer> pipe_link_set;
