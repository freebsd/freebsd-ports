Obtained from:	https://github.com/mapnik/mapnik/commit/f68291c5b47b5189d967dba01542262f2013da53

--- plugins/input/ogr/ogr_datasource.hpp.orig
+++ plugins/input/ogr/ogr_datasource.hpp
@@ -63,7 +63,7 @@ class ogr_datasource : public mapnik::datasource
     mapnik::datasource::datasource_t type_;
     std::string dataset_name_;
     std::string index_name_;
-    OGRDataSource* dataset_;
+    gdal_dataset_type dataset_;
     ogr_layer_ptr layer_;
     std::string layer_name_;
     mapnik::layer_descriptor desc_;
