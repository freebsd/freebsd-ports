--- src/las_c_api.cpp.orig	2009-10-02 17:48:41 UTC
+++ src/las_c_api.cpp
@@ -41,17 +41,17 @@
  * OF SUCH DAMAGE.
  ****************************************************************************/
 
-#include <liblas/liblas.hpp>
-#include <liblas/lasreader.hpp>
-#include <liblas/laserror.hpp>
-#include <liblas/laswriter.hpp>
-#include <liblas/lasfile.hpp>
-#include <liblas/exception.hpp>
-#include <liblas/lasvariablerecord.hpp>
-#include <liblas/guid.hpp>
-#include <liblas/lasspatialreference.hpp>
-#include <liblas/capi/las_config.h>
-#include <liblas/capi/las_version.h>
+#include <liblas12/liblas.hpp>
+#include <liblas12/lasreader.hpp>
+#include <liblas12/laserror.hpp>
+#include <liblas12/laswriter.hpp>
+#include <liblas12/lasfile.hpp>
+#include <liblas12/exception.hpp>
+#include <liblas12/lasvariablerecord.hpp>
+#include <liblas12/guid.hpp>
+#include <liblas12/lasspatialreference.hpp>
+#include <liblas12/capi/las_config.h>
+#include <liblas12/capi/las_version.h>
 
 typedef struct LASWriterHS *LASWriterH;
 typedef struct LASReaderHS *LASReaderH;
@@ -745,7 +745,7 @@ LAS_DLL LASErrorEnum LASHeader_SetProjectId(LASHeaderH
 
     try {
         liblas::guid id;
-        id = liblas::guid::guid(value);
+        id = liblas::guid(value);
         ((LASHeader*) hHeader)->SetProjectId(id);    
     } catch (std::exception const& e)
     {
@@ -1542,7 +1542,7 @@ LAS_DLL LASGuidH LASGuid_CreateFromString(const char* 
     VALIDATE_LAS_POINTER1(string, "LASGuid_CreateFromString", NULL);    
     liblas::guid id;
     try {
-        id = liblas::guid::guid(string);
+        id = liblas::guid(string);
         return (LASGuidH) new liblas::guid(id);
     }
     catch (std::exception const& e) {
