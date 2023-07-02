--- pv_metadata.h.orig	2023-03-27 07:19:09 UTC
+++ pv_metadata.h
@@ -234,7 +234,7 @@ struct metadata_type
       std::cout << result->key() << ": "
                 << result->value() << std::endl ;
 
-      _result = result->value().toLong() ;
+      _result = result->value().toInt64() ;
       return true ;
     }
     return false ;
@@ -665,7 +665,7 @@ struct metadata_type
             result = xmpData.findKey ( key ) ;
             if ( result != xmpData.end() )
             {
-              lux_uncropped_width = result->value().toLong() ;
+              lux_uncropped_width = result->value().toInt64() ;
             }
 
             lux_uncropped_height = -1 ;
@@ -673,7 +673,7 @@ struct metadata_type
             result = xmpData.findKey ( key ) ;
             if ( result != xmpData.end() )
             {
-              lux_uncropped_height = result->value().toLong() ;
+              lux_uncropped_height = result->value().toInt64() ;
             }
 
             lux_cropping_active = false ;
@@ -681,7 +681,7 @@ struct metadata_type
             result = xmpData.findKey ( key ) ;
             if ( result != xmpData.end() )
             {
-              lux_cropping_active = result->value().toLong() ;
+              lux_cropping_active = result->value().toInt64() ;
             }
 
             lux_cropped_width = -1 ;
@@ -689,7 +689,7 @@ struct metadata_type
             result = xmpData.findKey ( key ) ;
             if ( result != xmpData.end() )
             {
-              lux_cropped_width = result->value().toLong() ;
+              lux_cropped_width = result->value().toInt64() ;
             }
 
             lux_cropped_height = -1 ;
@@ -697,7 +697,7 @@ struct metadata_type
             result = xmpData.findKey ( key ) ;
             if ( result != xmpData.end() )
             {
-              lux_cropped_height = result->value().toLong() ;
+              lux_cropped_height = result->value().toInt64() ;
             }
 
             lux_crop_x0 = -1 ;
@@ -705,7 +705,7 @@ struct metadata_type
             result = xmpData.findKey ( key ) ;
             if ( result != xmpData.end() )
             {
-              lux_crop_x0 = result->value().toLong() ;
+              lux_crop_x0 = result->value().toInt64() ;
             }
 
             lux_crop_y0 = -1 ;
@@ -713,7 +713,7 @@ struct metadata_type
             result = xmpData.findKey ( key ) ;
             if ( result != xmpData.end() )
             {
-              lux_crop_y0 = result->value().toLong() ;
+              lux_crop_y0 = result->value().toInt64() ;
             }
 
             lux_crop_x1 = -1 ;
@@ -721,7 +721,7 @@ struct metadata_type
             result = xmpData.findKey ( key ) ;
             if ( result != xmpData.end() )
             {
-              lux_crop_x1 = result->value().toLong() ;
+              lux_crop_x1 = result->value().toInt64() ;
             }
 
             lux_crop_y1 = -1 ;
@@ -729,7 +729,7 @@ struct metadata_type
             result = xmpData.findKey ( key ) ;
             if ( result != xmpData.end() )
             {
-              lux_crop_y1 = result->value().toLong() ;
+              lux_crop_y1 = result->value().toInt64() ;
             }
 
             if ( lux_cropping_active )
@@ -790,42 +790,42 @@ struct metadata_type
             result = xmpData.findKey ( key ) ;
             if ( result != xmpData.end() )
             {
-              FullPanoHeightPixels = result->value().toLong() ;
+              FullPanoHeightPixels = result->value().toInt64() ;
             }
 
             key = Exiv2::XmpKey ( std::string ( "Xmp.GPano.FullPanoWidthPixels" ) ) ;
             result = xmpData.findKey ( key ) ;
             if ( result != xmpData.end() )
             {
-              FullPanoWidthPixels = result->value().toLong() ;
+              FullPanoWidthPixels = result->value().toInt64() ;
             }
 
             key = Exiv2::XmpKey ( std::string ( "Xmp.GPano.CroppedAreaImageHeightPixels" ) ) ;
             result = xmpData.findKey ( key ) ;
             if ( result != xmpData.end() )
             {
-              CroppedAreaImageHeightPixels = result->value().toLong() ;
+              CroppedAreaImageHeightPixels = result->value().toInt64() ;
             }
 
             key = Exiv2::XmpKey ( std::string ( "Xmp.GPano.CroppedAreaImageWidthPixels" ) ) ;
             result = xmpData.findKey ( key ) ;
             if ( result != xmpData.end() )
             {
-              CroppedAreaImageWidthPixels = result->value().toLong() ;
+              CroppedAreaImageWidthPixels = result->value().toInt64() ;
             }
 
             key = Exiv2::XmpKey ( std::string ( "Xmp.GPano.CroppedAreaLeftPixels" ) ) ;
             result = xmpData.findKey ( key ) ;
             if ( result != xmpData.end() )
             {
-              CroppedAreaLeftPixels = result->value().toLong() ;
+              CroppedAreaLeftPixels = result->value().toInt64() ;
             }
 
             key = Exiv2::XmpKey ( std::string ( "Xmp.GPano.CroppedAreaTopPixels" ) ) ;
             result = xmpData.findKey ( key ) ;
             if ( result != xmpData.end() )
             {
-              CroppedAreaTopPixels = result->value().toLong() ;
+              CroppedAreaTopPixels = result->value().toInt64() ;
             }
 
             // currently we only process GPano data if projection is equirectangular
