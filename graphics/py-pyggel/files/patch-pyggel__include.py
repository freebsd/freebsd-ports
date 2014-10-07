--- pyggel/include.py.orig	2014-10-07 16:52:11 UTC
+++ pyggel/include.py
@@ -27,7 +27,7 @@
     ANI_AVAILABLE = False
 
 try:
-    import Image as PIL
+    from PIL import Image as PIL
     PIL_AVAILABLE = True
 except:
     PIL_AVAILABLE = False
