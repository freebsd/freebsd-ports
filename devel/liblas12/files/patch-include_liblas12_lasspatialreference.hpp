--- include/liblas12/lasspatialreference.hpp.orig	2009-10-02 17:48:41 UTC
+++ include/liblas12/lasspatialreference.hpp
@@ -42,12 +42,12 @@
 #ifndef LIBLAS_LASSPATIALREFERENCE_HPP_INCLUDED
 #define LIBLAS_LASSPATIALREFERENCE_HPP_INCLUDED
 
-#include <liblas/lasvariablerecord.hpp>
-#include <liblas/cstdint.hpp>
-#include <liblas/detail/fwd.hpp>
-#include <liblas/detail/utility.hpp>
-#include <liblas/exception.hpp>
-#include <liblas/capi/las_config.h>
+#include <liblas12/lasvariablerecord.hpp>
+#include <liblas12/cstdint.hpp>
+#include <liblas12/detail/fwd.hpp>
+#include <liblas12/detail/utility.hpp>
+#include <liblas12/exception.hpp>
+#include <liblas12/capi/las_config.h>
 
 // GDAL OSR
 #ifdef HAVE_GDAL
