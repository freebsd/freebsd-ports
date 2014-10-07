--- impressive.py.orig	2014-10-04 23:28:04 UTC
+++ impressive.py
@@ -182,8 +182,8 @@
     from OpenGL.GL import *
     import pygame
     from pygame.locals import *
-    import Image, ImageDraw, ImageFont, ImageFilter
-    import TiffImagePlugin, BmpImagePlugin, JpegImagePlugin, PngImagePlugin, PpmImagePlugin
+    from PIL import Image, ImageDraw, ImageFont, ImageFilter
+    from PIL import TiffImagePlugin, BmpImagePlugin, JpegImagePlugin, PngImagePlugin, PpmImagePlugin
 except (ValueError, ImportError), err:
     print >>sys.stderr, "Oops! Cannot load necessary modules:", err
     print >>sys.stderr, """To use Impressive, you need to install the following Python modules:
