--- src/qt/YabauseThread.cpp.orig
+++ src/qt/YabauseThread.cpp
@@ -18,6 +18,9 @@
 	along with Yabause; if not, write to the Free Software
 	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 */
+
+#include <time.h>
+
 #include "YabauseThread.h"
 #include "Settings.h"
 #include "VolatileSettings.h"
