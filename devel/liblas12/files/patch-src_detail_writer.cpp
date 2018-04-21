--- src/detail/writer.cpp.orig	2009-10-02 17:48:41 UTC
+++ src/detail/writer.cpp
@@ -39,13 +39,13 @@
  * OF SUCH DAMAGE.
  ****************************************************************************/
 
-#include <liblas/detail/writer.hpp>
-#include <liblas/detail/writer10.hpp>
-#include <liblas/detail/writer11.hpp>
-#include <liblas/detail/writer12.hpp>
-#include <liblas/lasheader.hpp>
-#include <liblas/laspoint.hpp>
-#include <liblas/lasspatialreference.hpp>
+#include <liblas12/detail/writer.hpp>
+#include <liblas12/detail/writer10.hpp>
+#include <liblas12/detail/writer11.hpp>
+#include <liblas12/detail/writer12.hpp>
+#include <liblas12/lasheader.hpp>
+#include <liblas12/laspoint.hpp>
+#include <liblas12/lasspatialreference.hpp>
 
 #ifdef HAVE_GDAL
 #include <ogr_srs_api.h>
