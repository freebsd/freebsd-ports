--- normcap/clipboard/handlers/xclip.py.orig	2024-05-08 15:08:46 UTC
+++ normcap/clipboard/handlers/xclip.py
@@ -31,7 +31,7 @@ def is_compatible() -> bool:
 
 
 def is_compatible() -> bool:
-    if sys.platform != "linux":
+    if sys.platform != "linux" and sys.platform != "freebsd":
         logger.debug("%s is not compatible on non-Linux systems", __name__)
         return False
 
