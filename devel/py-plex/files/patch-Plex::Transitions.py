--- Plex/Transitions.py.orig	Sun Dec  5 11:01:02 2004
+++ Plex/Transitions.py	Sun Dec  5 11:01:32 2004
@@ -83,11 +83,11 @@
       self.get_special(event).update(new_set)
   
   def get_epsilon(self,
-    None = None):
+    _None = None):
     """
     Return the mapping for epsilon, or None.
     """
-    return self.special.get('', None)
+    return self.special.get('', _None)
   
   def items(self,
     len = len):
