--- engine/SCons/Script/Main.py.orig	Wed Feb 16 03:12:11 2005
+++ engine/SCons/Script/Main.py	Sat Mar 19 23:40:24 2005
@@ -1024,7 +1034,7 @@
                 node = None
         return node
 
-    nodes = filter(lambda x: x is not None, map(Entry, targets))
+    nodes = filter(None, map(Entry, targets))
 
     task_class = BuildTask	# default action is to build targets
     opening_message = "Building targets ..."
