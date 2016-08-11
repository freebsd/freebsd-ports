--- src/modules/Covers.py.orig	2011-09-19 10:09:25 UTC
+++ src/modules/Covers.py
@@ -124,7 +124,7 @@ class Covers(modules.ThreadedModule):
 
     def generateFullSizeCover(self, inFile, outFile, format):
         """ Resize inFile if needed, and write it to outFile (outFile and inFile may be equal) """
-        import Image
+        from PIL import Image
 
         try:
             # Open the image
@@ -144,7 +144,7 @@ class Covers(modules.ThreadedModule):
 
     def generateThumbnail(self, inFile, outFile, format):
         """ Generate a thumbnail from inFile (e.g., resize it) and write it to outFile (outFile and inFile may be equal) """
-        import Image
+        from PIL import Image
 
         try:
             # Open the image
