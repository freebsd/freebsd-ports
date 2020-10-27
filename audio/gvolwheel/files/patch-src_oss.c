--- src/oss.c.orig	2020-08-01 09:32:59 UTC
+++ src/oss.c
@@ -17,11 +17,14 @@
  * along with this program. If not, see <http://www.gnu.org/licenses/>.
  */
 
-#include <linux/soundcard.h>
+#include <sys/unistd.h>
+#include <sys/soundcard.h>
 #include <fcntl.h>
 #include <sys/ioctl.h>
 
 #include "oss.h"
+
+struct stereo_volume vol;
 
 static char *default_device = "/dev/mixer";
 
