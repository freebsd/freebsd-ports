--- options.h.orig	2024-04-22 10:18:21 UTC
+++ options.h
@@ -136,7 +136,7 @@ yes_no  ( grey_edge , true )
 yes_no  ( fully_covered , false )
 yes_no  ( fuse , false )
 yes_no  ( grey_edge , true )
-option  ( gui_font , "" )
+option  ( gui_font , "%%GUIFONT%%" )
 integer ( gui_extent , 0 )
 real    ( gui_scale_factor , 0.0 )
 yes_no  ( gpu_for_srgb , false )
