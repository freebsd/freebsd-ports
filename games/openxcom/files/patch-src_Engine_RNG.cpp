--- src/Engine/RNG.cpp.orig	2014-06-13 19:14:43 UTC
+++ src/Engine/RNG.cpp
@@ -17,6 +17,7 @@
  * along with OpenXcom.  If not, see <http://www.gnu.org/licenses/>.
  */
 #include "RNG.h"
+#include <limits>
 #include <math.h>
 #include <time.h>
 
@@ -86,7 +87,7 @@ int generate(int min, int max)
 double generate(double min, double max)
 {
 	double num = next();
-	return (double)(num / ((double)UINT64_MAX / (max - min)) + min);
+	return (double)(num / ((double)std::numeric_limits<uint64_t>::max() / (max - min)) + min);
 }
 
 /**
