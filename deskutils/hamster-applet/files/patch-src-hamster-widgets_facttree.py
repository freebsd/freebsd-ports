--- src/hamster/widgets/facttree.py	2010-06-22 13:59:09.000000000 +0400
+++ src/hamster/widgets/facttree.py	2010-09-26 01:31:57.000000000 +0400
@@ -20,8 +20,8 @@
 import gtk, gobject
 import datetime as dt
 
-from .hamster import stuff
-from .hamster.stuff import format_duration, format_activity
+from hamster import stuff
+from hamster.stuff import format_duration, format_activity
 from tags import Tag
 
 import pango
