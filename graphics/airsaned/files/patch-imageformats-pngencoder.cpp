--- imageformats/pngencoder.cpp.orig	2021-02-01 18:41:51 UTC
+++ imageformats/pngencoder.cpp
@@ -17,11 +17,17 @@ along with this program.  If not, see <http://www.gnu.
 */
 
 #include "pngencoder.h"
+#ifdef __FreeBSD__
+#include <png.h>
+#else
 #include <libpng/png.h>
+#endif
 #include <stdexcept>
 #include <vector>
 #if __APPLE__
 #include <machine/endian.h>
+#elif __FreeBSD__
+#include <sys/endian.h>
 #else
 #include <endian.h>
 #endif
