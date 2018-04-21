--- src/detail/reader.cpp.orig	2009-10-02 17:48:41 UTC
+++ src/detail/reader.cpp
@@ -39,12 +39,12 @@
  * OF SUCH DAMAGE.
  ****************************************************************************/
  
-#include <liblas/detail/reader.hpp>
-#include <liblas/detail/reader10.hpp>
-#include <liblas/detail/reader11.hpp>
-#include <liblas/detail/reader12.hpp>
-#include <liblas/lasheader.hpp>
-#include <liblas/laspoint.hpp>
+#include <liblas12/detail/reader.hpp>
+#include <liblas12/detail/reader10.hpp>
+#include <liblas12/detail/reader11.hpp>
+#include <liblas12/detail/reader12.hpp>
+#include <liblas12/lasheader.hpp>
+#include <liblas12/laspoint.hpp>
 // 
 // // GeoTIFF
 // #ifdef HAVE_LIBGEOTIFF
