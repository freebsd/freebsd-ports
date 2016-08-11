--- src/libtomahawk/utils/TomahawkUtils.cpp.orig	2015-04-15 04:41:40 UTC
+++ src/libtomahawk/utils/TomahawkUtils.cpp
@@ -19,6 +19,8 @@
  *   along with Tomahawk. If not, see <http://www.gnu.org/licenses/>.
  */
 
+#include <unistd.h>
+
 #include "utils/TomahawkUtils.h"
 
 #include "config.h"
@@ -183,7 +185,7 @@ appDataDir()
         }
     #elif defined(Q_OS_MAC)
         path = appSupportFolderPath();
-    #elif defined(Q_OS_LINUX)
+    #elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
         path = QDir::home().filePath( ".local/share" );
     #else
         path = QCoreApplication::applicationDirPath();
