--- src/modules/Covers.py.orig	2014-10-07 12:26:08 UTC
+++ src/modules/Covers.py
@@ -124,7 +124,7 @@
 
     def generateFullSizeCover(self, inFile, outFile, format):
         """ Resize inFile if needed, and write it to outFile (outFile and inFile may be equal) """
-        import Image
+        from PIL import Image
 
         try:
             # Open the image
@@ -144,7 +144,7 @@
 
     def generateThumbnail(self, inFile, outFile, format):
         """ Generate a thumbnail from inFile (e.g., resize it) and write it to outFile (outFile and inFile may be equal) """
-        import Image
+        from PIL import Image
 
         try:
             # Open the image
