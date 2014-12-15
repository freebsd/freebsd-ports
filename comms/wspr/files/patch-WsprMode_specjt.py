--- WsprMod/specjt.py.orig	2014-12-14 19:17:21.630624057 -0500
+++ WsprMod/specjt.py	2014-12-14 19:19:41.021613990 -0500
@@ -34,10 +34,7 @@
 import tkinter.messagebox
 from . import w
 
-try:
-    from numpy.oldnumeric import zeros, multiarray
-except:
-    from Numeric import zeros, multiarray
+from numpy import zeros, multiarray
 import Image, ImageTk, ImageDraw
 from .palettes import colormapblue, colormapgray0, colormapHot, \
      colormapAFMHot, colormapgray1, colormapLinrad, Colormap2Palette
