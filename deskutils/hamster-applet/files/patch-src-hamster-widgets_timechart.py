--- src/hamster/widgets/timechart.py	2010-06-22 13:59:09.000000000 +0400
+++ src/hamster/widgets/timechart.py	2010-09-26 01:33:04.000000000 +0400
@@ -20,7 +20,7 @@
 import os  # for locale
 import gtk, pango
 
-from .hamster import graphics
+from hamster import graphics
 
 import time, datetime as dt
 import calendar
