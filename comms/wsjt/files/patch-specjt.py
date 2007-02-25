--- specjt.py.orig	Fri Feb  2 16:45:39 2007
+++ specjt.py	Fri Feb  2 17:10:25 2007
@@ -10,7 +10,7 @@
 import string
 import cPickle
 #import Numeric
-from Numeric import zeros, multiarray
+from numpy.oldnumeric import zeros, multiarray
 import Image, ImageTk, ImageDraw
 from palettes import colormapblue, colormapgray0, colormapHot, \
      colormapAFMHot, colormapgray1, colormapLinrad, Colormap2Palette
