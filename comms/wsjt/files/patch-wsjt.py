--- wsjt.py.orig	Fri Feb  2 16:45:49 2007
+++ wsjt.py	Fri Feb  2 17:10:03 2007
@@ -8,7 +8,7 @@
 import g,os,time
 import Audio
 from math import log10
-from Numeric import zeros
+from numpy.oldnumeric import zeros
 import dircache
 import Image,ImageTk  #, ImageDraw
 from palettes import colormapblue, colormapgray0, colormapHot, \
