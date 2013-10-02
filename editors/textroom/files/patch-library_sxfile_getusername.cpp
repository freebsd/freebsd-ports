--- library/sxfile/getusername.cpp.orig	2011-01-15 18:50:03.000000000 +0000
+++ library/sxfile/getusername.cpp
@@ -16,6 +16,7 @@
     Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
 
+#include <unistd.h>
 #include "getusername.h"
 
 #ifdef Q_OS_UNIX
