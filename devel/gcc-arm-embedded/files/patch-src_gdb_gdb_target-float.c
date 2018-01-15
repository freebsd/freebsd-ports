--- src/gdb/gdb/target-float.c.orig	2018-01-15 13:56:10.319799000 +0300
+++ src/gdb/gdb/target-float.c	2018-01-15 13:59:23.017127000 +0300
@@ -17,12 +17,14 @@
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.  */
 
+#include <stdint.h>
+#define MPFR_USE_INTMAX_T 1
+
 #include "defs.h"
 #include "gdbtypes.h"
 #include "floatformat.h"
 #include "target-float.h"
 
-
 /* Target floating-point operations.
 
    We provide multiple implementations of those operations, which differ
