--- src/lasheader.cpp.orig	2009-10-02 17:48:41 UTC
+++ src/lasheader.cpp
@@ -40,11 +40,11 @@
  * OF SUCH DAMAGE.
  ****************************************************************************/
 
-#include <liblas/lasheader.hpp>
-#include <liblas/cstdint.hpp>
-#include <liblas/guid.hpp>
-#include <liblas/detail/utility.hpp>
-#include <liblas/lasspatialreference.hpp>
+#include <liblas12/lasheader.hpp>
+#include <liblas12/cstdint.hpp>
+#include <liblas12/guid.hpp>
+#include <liblas12/detail/utility.hpp>
+#include <liblas12/lasspatialreference.hpp>
 
 // GeoTIFF
 #ifdef HAVE_LIBGEOTIFF
