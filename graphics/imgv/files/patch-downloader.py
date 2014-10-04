--- downloader.py.orig	2014-10-04 23:19:16 UTC
+++ downloader.py
@@ -7,7 +7,7 @@
 if platform == 'win32':
     import BmpImagePlugin, JpegImagePlugin, PngImagePlugin, SgiImagePlugin, SunImagePlugin, TgaImagePlugin, TiffImagePlugin, PcxImagePlugin, PpmImagePlugin, XpmImagePlugin # for py2exe to work with PIL
 try:
-    import Image # PIL
+    from PIL import Image # PIL
 except:
     print "You are missing the python-imaging package (PIL). Please install it"
 from usr_event import check_quit
