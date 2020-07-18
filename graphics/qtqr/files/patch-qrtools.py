--- qrtools.py.orig	2020-07-15 18:00:04 UTC
+++ qrtools.py
@@ -29,6 +29,7 @@ import sys
 import time
 import shutil
 import hashlib
+import numpy as np
 try:
     import zbar
 except ImportError:
@@ -210,35 +211,19 @@ class QR(object):
     def decode(self, filename=None, image=None):
         self.filename = filename or self.filename
         if self.filename is not None or image is not None:
-            scanner = zbar.ImageScanner()
-            # configure the reader
-            scanner.parse_config('enable')
-            # obtain image data
-            if image is not None:
-                pil = image.convert('L')
-            else:
-                pil = Image.open(self.filename).convert('L')
-            width, height = pil.size
-            try:
-                raw = pil.tostring()
-            except:
-                raw = pil.tobytes()
-            # wrap image data
-            image = zbar.Image(width, height, 'Y800', raw)
-            # scan the image for barcodes
+            image = np.array(Image.open(self.filename).convert('L'))
+            scanner = zbar.Scanner()
             result = scanner.scan(image)
+
             # extract results
             if result == 0: 
                 return False
             else:
-                for symbol in image:
-                    pass
-                # clean up
                 del(image)
-                #Assuming data is encoded in utf8
-                self.data = symbol.data
-                self.data_type = self.data_recognise()
-                return True
+                for res in result:
+                    self.data = res.data.decode('utf8')
+                    self.data_type = self.data_recognise()
+                    return True
         else:
             return False
 
