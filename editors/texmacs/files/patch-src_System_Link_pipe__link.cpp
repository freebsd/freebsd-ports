--- ./src/System/Link/pipe_link.cpp.orig	Sun Oct  3 13:26:37 2004
+++ ./src/System/Link/pipe_link.cpp	Sat Oct 23 17:39:48 2004
@@ -10,6 +10,8 @@
 * 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 ******************************************************************************/
 
+#include <osreldate.h>
+
 #include "pipe_link.hpp"
 #include "sys_utils.hpp"
 #include "hashset.hpp"
@@ -23,8 +25,12 @@
 #ifdef OS_WIN32
 #include <sys/misc.h>
 #endif
+#if __FreeBSD_version < 500000
 #ifndef __APPLE__
 #include <malloc.h>
+#endif
+#else
+#include <stdlib.h>
 #endif
 
 hashset<pointer> pipe_link_set;
