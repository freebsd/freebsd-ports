--- gmapcatcher/mapArgs.py.orig	2012-04-28 21:35:10.000000000 +0800
+++ gmapcatcher/mapArgs.py	2012-09-07 10:57:29.000000000 +0800
@@ -45,10 +45,10 @@
         print '                very useful to download maps of entire world'
         print ' '
         print 'SAMPLE USAGE'
-        print '  download --location="Paris, France"'
-        print '  download --min-zoom=13 --full-range'
-        print '  download --latitude=37.979180 --longitude=23.716647'
-        print '  download --gpx=myfile.gpx --width=2'
+        print '  mapdownloader --location="Paris, France"'
+        print '  mapdownloader --min-zoom=13 --full-range'
+        print '  mapdownloader --latitude=37.979180 --longitude=23.716647'
+        print '  mapdownloader --gpx=myfile.gpx --width=2'
 
     def __init__(self, arrArgs=()):
         if len(arrArgs) > 1:
@@ -96,7 +96,7 @@
                         self.lng_range = 179
 
     def __str__(self):
-        return ("download.py --max-zoom=%s --min-zoom=%s" \
+        return ("mapdownloader --max-zoom=%s --min-zoom=%s" \
                 + " --latitude=%s --longitude=%s" \
                 + " --width=%s --height=%s") % \
                (self.max_zl, self.min_zl,
