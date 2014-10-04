--- wspr.py.orig	2014-10-04 14:29:49 UTC
+++ wspr.py
@@ -14,7 +14,7 @@
     from Numeric import zeros
 import array
 import dircache
-import Image, ImageTk, ImageDraw
+from PIL import Image, ImageTk, ImageDraw
 from WsprMod.palettes import colormapblue, colormapgray0, colormapHot, \
      colormapAFMHot, colormapgray1, colormapLinrad, Colormap2Palette
 from types import *
