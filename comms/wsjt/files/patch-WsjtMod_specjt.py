--- WsjtMod/specjt.py.orig	2011-09-13 15:56:59.000000000 -0400
+++ WsjtMod/specjt.py	2014-12-15 21:26:06.000000000 -0500
@@ -11,13 +11,9 @@
 import cPickle
 import tkMessageBox
 
-try:
-    from numpy.oldnumeric import zeros, multiarray
-#    print "specjt importing from numpy"
-except:
-    from Numeric import zeros, multiarray
-#    print "specjt importing from Numeric"
-import Image, ImageTk, ImageDraw
+from numpy import zeros
+from numpy.core import multiarray
+from PIL import Image, ImageTk, ImageDraw
 from palettes import colormapblue, colormapgray0, colormapHot, \
      colormapAFMHot, colormapgray1, colormapLinrad, Colormap2Palette
 #import wsjt                         #Is this OK to do?
@@ -76,7 +72,7 @@
 ttot=0.0
 
 c=Canvas()
-a=zeros(225000,'s')
+##a=zeros(225000,'s')
 im=Image.new('P',(750,300))
 line0=Image.new('P',(750,1))      #Image fragment for top line of waterfall
 draw=ImageDraw.Draw(im)
