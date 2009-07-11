--- codecs/xpm.cc.orig	2009-07-02 18:34:51.000000000 -0400
+++ codecs/xpm.cc	2009-07-02 18:48:45.000000000 -0400
@@ -131,6 +131,7 @@
       // Type: c -> colour, m -> monochrome, g -> grayscale, and s -> symbolic
       if (type != "c") {
 	std::cerr << "XPM color type: " << type << " not yet implemented." << std::endl;
+	delete[] rmap; delete[] gmap; delete[] bmap;
 	return false;
       }
       
@@ -197,7 +198,7 @@
     }
   
   colorspace_de_palette (image, colors, rmap, gmap, bmap);
-  delete (rmap); delete (gmap); delete (bmap);
+  delete[] rmap; delete[] gmap; delete[] bmap;
   rmap = gmap = bmap = 0;
 
   return true;
