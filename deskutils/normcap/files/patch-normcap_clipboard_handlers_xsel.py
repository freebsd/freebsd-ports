--- normcap/clipboard/handlers/xsel.py.orig	2024-05-08 15:36:37 UTC
+++ normcap/clipboard/handlers/xsel.py
@@ -29,7 +29,7 @@ def is_compatible() -> bool:
 
 
 def is_compatible() -> bool:
-    if sys.platform != "linux":
+    if sys.platform != "linux" and sys.platform != "freebsd":
         logger.debug("%s is not compatible on non-Linux systems", __name__)
         return False
 
