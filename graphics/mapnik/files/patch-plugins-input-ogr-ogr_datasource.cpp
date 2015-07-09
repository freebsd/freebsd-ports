Obtained from:	https://github.com/mapnik/mapnik/commit/f68291c5b47b5189d967dba01542262f2013da53
		https://github.com/mapnik/mapnik/commit/f0821d897f66c31755f7012b68191a2ec7a060fb

--- plugins/input/ogr/ogr_datasource.cpp.orig	2013-06-04 01:35:27 UTC
+++ plugins/input/ogr/ogr_datasource.cpp
@@ -72,7 +72,11 @@ ogr_datasource::~ogr_datasource()
 {
     // free layer before destroying the datasource
     layer_.free_layer();
+#if GDAL_VERSION_MAJOR >= 2
+    GDALClose(( GDALDatasetH) dataset_);
+#else
     OGRDataSource::DestroyDataSource (dataset_);
+#endif
 }
 
 void ogr_datasource::init(mapnik::parameters const& params)
@@ -82,6 +86,7 @@ void ogr_datasource::init(mapnik::parame
 #endif
 
     // initialize ogr formats
+    // NOTE: in GDAL >= 2.0 this is the same as GDALAllRegister()
     OGRRegisterAll();
 
     boost::optional<std::string> file = params.get<std::string>("file");
@@ -112,17 +117,26 @@ void ogr_datasource::init(mapnik::parame
 
     if (! driver.empty())
     {
+#if GDAL_VERSION_MAJOR >= 2
+        unsigned int nOpenFlags = GDAL_OF_READONLY | GDAL_OF_VECTOR;
+        const char* papszAllowedDrivers[] = { driver.c_str(), NULL };
+        dataset_ = static_cast<gdal_dataset_type>(GDALOpenEx(dataset_name_.c_str(),nOpenFlags,papszAllowedDrivers,NULL,NULL));
+#else
         OGRSFDriver * ogr_driver = OGRSFDriverRegistrar::GetRegistrar()->GetDriverByName(driver.c_str());
         if (ogr_driver && ogr_driver != NULL)
         {
             dataset_ = ogr_driver->Open((dataset_name_).c_str(), FALSE);
         }
-
+#endif
     }
     else
     {
         // open ogr driver
-        dataset_ = OGRSFDriverRegistrar::Open((dataset_name_).c_str(), FALSE);
+#if GDAL_VERSION_MAJOR >= 2
+        dataset_ = static_cast<gdal_dataset_type>(OGROpen(dataset_name_.c_str(), FALSE, NULL));
+#else
+        dataset_ = OGRSFDriverRegistrar::Open(dataset_name_.c_str(), FALSE);
+#endif
     }
 
     if (! dataset_)
