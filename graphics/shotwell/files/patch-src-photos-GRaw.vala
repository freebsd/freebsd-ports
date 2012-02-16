--- src/photos/GRaw.vala.orig	2012-02-15 17:13:51.000000000 -0800
+++ src/photos/GRaw.vala	2012-02-15 17:15:48.000000000 -0800
@@ -34,11 +34,11 @@
     OUT_OF_ORDER_CALL,
     NO_THUMBNAIL,
     UNSUPPORTED_THUMBNAIL,
-    CANNOT_ADDMASK,
     OUT_OF_MEMORY,
     DATA_ERROR,
     IO_ERROR,
     CANCELLED_BY_CALLBACK,
+    BAD_CROP,
     SYSTEM_ERROR
 }
 
@@ -163,10 +163,6 @@
         proc = new LibRaw.Processor(options);
     }
     
-    public void add_masked_borders_to_bitmap() {
-        proc.add_masked_borders_to_bitmap();
-    }
-    
     public void adjust_sizes_info_only() throws Exception {
         throw_exception("adjust_sizes_info_only", proc.adjust_sizes_info_only());
     }
@@ -215,10 +211,6 @@
         throw_exception("ppm_tiff_writer", proc.ppm_tiff_writer(filename));
     }
     
-    public void rotate_fuji_raw() throws Exception {
-        throw_exception("rotate_fuji_raw", proc.rotate_fuji_raw());
-    }
-    
     public void thumb_writer(string filename) throws Exception {
         throw_exception("thumb_writer", proc.thumb_writer(filename));
     }
@@ -262,7 +254,6 @@
         // camera_profile
         // bad_pixels
         // dark_frame
-        output_params->filtering_mode = LibRaw.Filtering.AUTOMATIC;
         output_params->output_bps = 8;
         // output_tiff
         output_params->user_flip = GRaw.Flip.FROM_SOURCE;
@@ -303,9 +294,6 @@
         case LibRaw.Result.UNSUPPORTED_THUMBNAIL:
             throw new Exception.UNSUPPORTED_THUMBNAIL(msg);
         
-        case LibRaw.Result.CANNOT_ADDMASK:
-            throw new Exception.CANNOT_ADDMASK(msg);
-        
         case LibRaw.Result.UNSUFFICIENT_MEMORY:
             throw new Exception.OUT_OF_MEMORY(msg);
         
@@ -317,6 +305,9 @@
         
         case LibRaw.Result.CANCELLED_BY_CALLBACK:
             throw new Exception.CANCELLED_BY_CALLBACK(msg);
+
+        case LibRaw.Result.BAD_CROP:
+            throw new Exception.BAD_CROP(msg);
         
         default:
             return;
