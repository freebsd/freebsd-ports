--- verbose.py.orig	2014-10-04 23:19:42 UTC
+++ verbose.py
@@ -12,7 +12,7 @@
 from usr_event import check_quit, hit_key
 if platform == 'win32':
     import BmpImagePlugin, JpegImagePlugin, PngImagePlugin, SgiImagePlugin, SunImagePlugin, TgaImagePlugin, TiffImagePlugin, PcxImagePlugin, PpmImagePlugin, XpmImagePlugin # for py2exe to work with PIL
-import Image # PIL
+from PIL import Image # PIL
 import pygame.font, pygame.event
 from pygame.transform import scale
 from pygame.display import update, flip, set_caption
