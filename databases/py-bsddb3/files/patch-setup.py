--- setup.py.orig	Mon Apr  9 12:29:06 2001
+++ setup.py	Mon Apr  9 12:29:15 2001
@@ -90,7 +90,7 @@
     if not status and string.find(results, 'libdb.') >= 0:
         static = 1
 
-    if static:
+    if 0:
         print """\
 \aWARNING:
 \tIt appears that the old bsddb module is staticly linked in the
