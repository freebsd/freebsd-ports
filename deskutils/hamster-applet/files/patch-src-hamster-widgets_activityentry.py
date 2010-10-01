--- src/hamster/widgets/activityentry.py	2010-06-22 13:59:09.000000000 +0400
+++ src/hamster/widgets/activityentry.py	2010-09-26 01:29:25.000000000 +0400
@@ -20,10 +20,10 @@
 import gtk, gobject
 import datetime as dt
 
-from .hamster.configuration import runtime
+from hamster.configuration import runtime
 
-from .hamster import stuff
-from .hamster.stuff import format_duration
+from hamster import stuff
+from hamster.stuff import format_duration
 
 class ActivityEntry(gtk.Entry):
     __gsignals__ = {
