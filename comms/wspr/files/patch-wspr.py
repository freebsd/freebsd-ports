--- wspr.py.orig	2014-12-14 19:16:10.079628932 -0500
+++ wspr.py	2014-12-14 19:16:18.894628427 -0500
@@ -50,7 +50,7 @@
 import Pmw
 from WsprMod import palettes
 from math import log10
-from numpy.oldnumeric import zeros
+from numpy import zeros
 import array
 ##import dircache
 from PIL import Image, ImageTk, ImageDraw
