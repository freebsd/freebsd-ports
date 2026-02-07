--- src/Engine/Language.cpp.orig	2019-08-03 22:25:23 UTC
+++ src/Engine/Language.cpp
@@ -17,6 +17,7 @@
  * along with OpenXcom.  If not, see <http://www.gnu.org/licenses/>.
  */
 #include "Language.h"
+#include <algorithm>
 #include <assert.h>
 #include <locale>
 #include <fstream>
