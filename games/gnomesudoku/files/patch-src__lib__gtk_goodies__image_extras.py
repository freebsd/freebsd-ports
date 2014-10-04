--- src/lib/gtk_goodies/image_extras.py.orig	2014-10-04 19:22:19 UTC
+++ src/lib/gtk_goodies/image_extras.py
@@ -1,4 +1,4 @@
-import Image,ImageOps
+from PIL import Image,ImageOps
 import gtk
 import string
 import StringIO
