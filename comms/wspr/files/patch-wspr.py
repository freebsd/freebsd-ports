--- wspr.py.orig	2017-09-27 19:55:15 UTC
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
