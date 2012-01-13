--- src/devices/cddalister.cpp.orig	2012-01-11 22:39:03.000000000 -0600
+++ src/devices/cddalister.cpp	2012-01-11 22:39:22.000000000 -0600
@@ -15,12 +15,12 @@
    along with Clementine.  If not, see <http://www.gnu.org/licenses/>.
 */
 
-#include <cdio/cdio.h>
 #include <QFileInfo>
 #include <QMutex>
 #include <QThread>
 #include <QWaitCondition>
 
+#include <cdio/cdio.h>
 #include "cddalister.h"
 #include "core/logging.h"
 #include "core/song.h"
