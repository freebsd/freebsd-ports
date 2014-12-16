--- WsprMod/specjt.py.orig	2014-12-15 21:51:30.000000000 -0500
+++ WsprMod/specjt.py	2014-12-15 21:54:38.000000000 -0500
@@ -34,10 +34,8 @@
 import tkinter.messagebox
 from . import w
 
-try:
-    from numpy.oldnumeric import zeros, multiarray
-except:
-    from Numeric import zeros, multiarray
+from numpy import zeros
+from numpy.core import multiarray
 import Image, ImageTk, ImageDraw
 from .palettes import colormapblue, colormapgray0, colormapHot, \
      colormapAFMHot, colormapgray1, colormapLinrad, Colormap2Palette
@@ -94,7 +92,7 @@
 ttot=0.0
 
 c=Canvas()
-a=zeros(225000,'s')
+##a=zeros(225000,'s')
 im=Image.new('P',(750,300))
 line0=Image.new('P',(750,1))      #Image fragment for top line of waterfall
 draw=ImageDraw.Draw(im)
