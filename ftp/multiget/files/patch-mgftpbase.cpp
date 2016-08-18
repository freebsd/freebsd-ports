--- mgftpbase.cpp.orig	2016-08-15 13:26:19 UTC
+++ mgftpbase.cpp
@@ -22,6 +22,8 @@
  *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
 
+#include <cstdlib>
+
 #ifdef WIN32
 #include <winsock2.h>
 #endif
