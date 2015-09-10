--- wspr.py.orig	2015-07-27 16:22:02 UTC
+++ wspr.py
@@ -50,7 +50,7 @@ from WsprMod import g
 import Pmw
 from WsprMod import palettes
 from math import log10
-from numpy.oldnumeric import zeros
+from numpy import zeros
 import array
 ##import dircache
 from PIL import Image, ImageTk, ImageDraw
