--- src/hamster/widgets/tags.py	2010-06-22 13:59:09.000000000 +0400
+++ src/hamster/widgets/tags.py	2010-09-26 01:32:32.000000000 +0400
@@ -21,9 +21,9 @@
 import pango, cairo
 from math import pi
 
-from .hamster import graphics
+from hamster import graphics
 
-from .hamster.configuration import runtime
+from hamster.configuration import runtime
 
 class TagsEntry(gtk.Entry):
     __gsignals__ = {
