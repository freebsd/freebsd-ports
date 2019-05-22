--- impressive.py.orig	2018-02-04 20:31:39 UTC
+++ impressive.py
@@ -6332,7 +6332,14 @@ def run_main():
             print >>sys.stderr, "Impressive version:", __version__
             print >>sys.stderr, "Python version:", sys.version
             print >>sys.stderr, "PyGame version:", pygame.__version__
-            print >>sys.stderr, "PIL version:", Image.VERSION
+            if hasattr(Image, "__version__"):  # Pillow >= 5.2
+                print >>sys.stderr, "PIL version: Pillow", Image.__version__
+            elif hasattr(Image, "PILLOW_VERSION"):  # Pillow < 7.0
+                print >>sys.stderr, "PIL version: Pillow", Image.PILLOW_VERSION
+            elif hasattr(Image, "VERSION"):  # classic PIL or Pillow 1.x
+                print >>sys.stderr, "PIL version: classic", Image.VERSION
+            else:
+                print >>sys.stderr, "PIL version: unknown"            
             if PDFRenderer:
                 print >>sys.stderr, "PDF renderer:", PDFRenderer.name
             else:
