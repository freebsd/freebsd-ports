--- weather/src/applet-load-icons.c.orig	2025-12-22 10:16:05 UTC
+++ weather/src/applet-load-icons.c
@@ -17,6 +17,7 @@
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include <math.h>
 #include <string.h>
 
 #include "applet-struct.h"
