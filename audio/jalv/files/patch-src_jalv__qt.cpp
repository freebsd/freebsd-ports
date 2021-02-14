--- src/jalv_qt.cpp.orig	2021-02-14 03:40:27 UTC
+++ src/jalv_qt.cpp
@@ -14,6 +14,8 @@
   OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
 
+#include <ctype.h> // workaround for error: use of undeclared identifier 'isascii'
+
 #include "jalv_internal.h"
 
 #include "lilv/lilv.h"
