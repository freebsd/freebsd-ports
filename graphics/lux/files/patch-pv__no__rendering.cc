--- pv_no_rendering.cc.orig	2023-03-27 07:19:09 UTC
+++ pv_no_rendering.cc
@@ -8828,7 +8828,7 @@ void store_rendered_image ( const job_type * p_job ,
  
       image->writeMetadata();
     }
-    catch ( Exiv2::AnyError& e )
+    catch ( Exiv2::Error& e )
     {
       std::cerr << "Caught Exiv2 exception '"
                 << e << "'\n" ;
