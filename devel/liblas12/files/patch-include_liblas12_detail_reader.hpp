--- include/liblas12/detail/reader.hpp.orig	2009-10-02 17:48:41 UTC
+++ include/liblas12/detail/reader.hpp
@@ -42,9 +42,9 @@
 #ifndef LIBLAS_DETAIL_READER_HPP_INCLUDED
 #define LIBLAS_DETAIL_READER_HPP_INCLUDED
 
-#include <liblas/cstdint.hpp>
-#include <liblas/lasspatialreference.hpp>
-#include <liblas/detail/fwd.hpp>
+#include <liblas12/cstdint.hpp>
+#include <liblas12/lasspatialreference.hpp>
+#include <liblas12/detail/fwd.hpp>
 
 #ifndef HAVE_GDAL
     typedef struct OGRCoordinateTransformationHS *OGRCoordinateTransformationH;
