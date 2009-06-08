--- Pyrex/Compiler/Errors.py.orig	2009-05-18 12:29:49.000000000 +0200
+++ Pyrex/Compiler/Errors.py	2009-05-18 12:32:21.000000000 +0200
@@ -14,7 +14,7 @@
     
     def __init__(self, position = None, message = ""):
         self.position = position
-        self.message = message
+        self._message = message
         if position:
             pos_str = "%s:%d:%d: " % position
         else:
