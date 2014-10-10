--- pysollib/mfxutil.py.orig	2014-10-08 15:37:56 UTC
+++ pysollib/mfxutil.py
@@ -41,18 +41,18 @@
 Image = ImageTk = ImageOps = None
 if TOOLKIT == 'tk':
     try: # PIL
-        import Image
-        import ImageTk
-        import ImageOps
+        from PIL import Image
+        from PIL import ImageTk
+        from PIL import ImageOps
     except ImportError:
         Image = None
     else:
         # for py2exe
-        import GifImagePlugin
-        import PngImagePlugin
-        import JpegImagePlugin
-        import BmpImagePlugin
-        import PpmImagePlugin
+        from PIL import GifImagePlugin
+        from PIL import PngImagePlugin
+        from PIL import JpegImagePlugin
+        from PIL import BmpImagePlugin
+        from PIL import PpmImagePlugin
         Image._initialized = 2
 
 
