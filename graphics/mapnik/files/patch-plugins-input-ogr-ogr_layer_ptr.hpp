Obtained from:	https://github.com/mapnik/mapnik/commit/f68291c5b47b5189d967dba01542262f2013da53
		https://github.com/mapnik/mapnik/commit/f0821d897f66c31755f7012b68191a2ec7a060fb

--- plugins/input/ogr/ogr_layer_ptr.hpp.orig
+++ plugins/input/ogr/ogr_layer_ptr.hpp
@@ -29,9 +29,16 @@
 // stl
 #include <stdexcept>
 
-// ogr
+// gdal
+#include <gdal_version.h>
 #include <ogrsf_frmts.h>
 
+#if GDAL_VERSION_MAJOR >= 2
+typedef GDALDataset* gdal_dataset_type;
+#else
+typedef OGRDataSource* gdal_dataset_type;
+#endif
+
 class ogr_layer_ptr
 {
 public:
@@ -62,7 +69,7 @@ class ogr_layer_ptr
         is_valid_ = false;
     }
 
-    void layer_by_name(OGRDataSource* const datasource,
+    void layer_by_name(gdal_dataset_type const datasource,
                        std::string const& layer_name)
     {
         free_layer();
@@ -84,7 +91,7 @@ class ogr_layer_ptr
 #endif
     }
 
-    void layer_by_index(OGRDataSource* const datasource,
+    void layer_by_index(gdal_dataset_type const datasource,
                         int layer_index)
     {
         free_layer();
@@ -110,7 +117,7 @@ class ogr_layer_ptr
 #endif
     }
 
-    void layer_by_sql(OGRDataSource* const datasource,
+    void layer_by_sql(gdal_dataset_type const datasource,
                       std::string const& layer_sql)
     {
         free_layer();
@@ -179,7 +186,7 @@ class ogr_layer_ptr
     }
 #endif
 
-    OGRDataSource* datasource_;
+    gdal_dataset_type datasource_;
     OGRLayer* layer_;
     std::string layer_name_;
     bool owns_layer_;
