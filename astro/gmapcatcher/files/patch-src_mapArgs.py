--- src/mapArgs.py.orig	2010-03-25 15:48:48.000000000 +0800
+++ src/mapArgs.py	2010-03-25 15:49:26.000000000 +0800
@@ -38,9 +38,9 @@
         print '                very useful to download maps of entire world'
         print ' '
         print 'SAMPLE USAGE'
-        print '  download.py --location="Paris, France"'
-        print '  download.py --min-zoom=13 --full-range'
-        print '  download.py --latitude=37.979180 --longitude=23.716647'
+        print '  gmapcatcher-download --location="Paris, France"'
+        print '  gmapcatcher-download --min-zoom=13 --full-range'
+        print '  gmapcatcher-download --latitude=37.979180 --longitude=23.716647'
 
     def __init__(self, arrArgs=()):
         if len(arrArgs) > 1:
