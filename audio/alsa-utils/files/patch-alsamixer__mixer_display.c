--- alsamixer/mixer_display.c~
+++ alsamixer/mixer_display.c
@@ -17,7 +17,9 @@
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */
 
+#ifdef __GLIBC__
 #define _C99_SOURCE /* lrint() */
+#endif
 #include "aconfig.h"
 #include <stdlib.h>
 #include <string.h>
