--- ./zutils.h.orig	2013-07-07 14:15:39.000000000 -0300
+++ ./zutils.h	2013-09-25 17:32:23.000000000 -0300
@@ -15,6 +15,9 @@
     along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include <sys/types.h>
+#include <signal.h>
+
 const char * const     Program_name = "Zutils";
 const char * const     program_name = "zutils";
 const char * const config_file_name = "zutilsrc";
