--- coders/rle.c.orig	2015-01-01 22:58:53.775440763 +0100
+++ coders/rle.c	2015-01-01 23:00:50.825507571 +0100
@@ -456,7 +456,7 @@
             if (IsValidColormapIndex(image,*p & mask,&index,exception) ==
                 MagickFalse)
               break;
-            *p=colormap[index];
+            *p=colormap[(ssize_t)index];
             p++;
           }
         else
@@ -467,7 +467,7 @@
                 if (IsValidColormapIndex(image,(size_t) (x*map_length+
                     (*p & mask)),&index,exception) == MagickFalse)
                   break;
-                *p=colormap[index];
+                *p=colormap[(ssize_t)index];
                 p++;
               }
         if ((i < (ssize_t) number_pixels) || (x < (ssize_t) number_planes))
