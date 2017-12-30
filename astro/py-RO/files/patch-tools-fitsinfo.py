--- tools/fitsinfo.py.orig	2014-09-18 18:19:45 UTC
+++ tools/fitsinfo.py
@@ -2,7 +2,7 @@
 from __future__ import absolute_import, division, print_function
 import argparse
 import numpy
-import pyfits
+import astropy.io.fits as pyfits
 
 def fitsInfo(filePath, hduList=None, showHeader=True, showStats=True):
     """Print information about a FITS file
