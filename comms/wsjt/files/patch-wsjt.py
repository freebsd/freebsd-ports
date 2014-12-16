--- wsjt.py.orig	2012-01-26 12:01:08.000000000 -0500
+++ wsjt.py	2014-12-15 21:21:29.000000000 -0500
@@ -10,14 +10,9 @@
 import os,time
 from WsjtMod import Audio
 from math import log10
-try:
-    from numpy.oldnumeric import zeros
-#    print "importing from numpy"
-except: 
-    from Numeric import zeros
-#    print "importing from Numeric"
+from numpy import zeros
 import dircache
-import Image,ImageTk  #, ImageDraw
+from PIL import Image, ImageTk #, ImageDraw
 from WsjtMod.palettes import colormapblue, colormapgray0, colormapHot, \
      colormapAFMHot, colormapgray1, colormapLinrad, Colormap2Palette
 from types import *
