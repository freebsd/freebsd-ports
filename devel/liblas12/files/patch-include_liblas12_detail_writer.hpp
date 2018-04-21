--- include/liblas12/detail/writer.hpp.orig	2009-10-02 17:48:41 UTC
+++ include/liblas12/detail/writer.hpp
@@ -42,9 +42,9 @@
 #ifndef LIBLAS_DETAIL_WRITER_HPP_INCLUDED
 #define LIBLAS_DETAIL_WRITER_HPP_INCLUDED
 
-#include <liblas/lasspatialreference.hpp>
-#include <liblas/detail/fwd.hpp>
-#include <liblas/detail/utility.hpp>
+#include <liblas12/lasspatialreference.hpp>
+#include <liblas12/detail/fwd.hpp>
+#include <liblas12/detail/utility.hpp>
 
 #ifndef HAVE_GDAL
     typedef struct OGRCoordinateTransformationHS *OGRCoordinateTransformationH;
