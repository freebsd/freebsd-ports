--- options.h.orig	2022-08-27 02:26:10 UTC
+++ options.h
@@ -132,7 +132,7 @@ yes_no  ( fullscreen , true )
 yes_no  ( fully_covered , false )
 yes_no  ( fuse , false )
 yes_no  ( grey_edge , true )
-option  ( gui_font , "" )
+option  ( gui_font , "%%GUIFONT%%" )
 integer ( gui_extent , 0 )
 real    ( gui_scale_factor , 0.0 )
 yes_no  ( hdr_merge , false )
