--- display/TargetLabel.py.orig	Mon Feb 23 09:55:46 2004
+++ display/TargetLabel.py	Mon Feb 23 09:56:50 2004
@@ -103,7 +103,14 @@
 
 # determine the locale
 import commands
+import string
 fail, CHARMAP = commands.getstatusoutput("locale charmap")
+if (fail or not CHARMAP):
+    fail, CHARMAP = commands.getstatusoutput("echo $MM_CHARSET")
+    if (fail or not CHARMAP):
+        fail, CHARMAP = commands.getstatusoutput("echo $LANG")
+        CHARMAP = CHARMAP[string.find(CHARMAP, ".")+1:len(CHARMAP)]
+
 if (fail or not CHARMAP):
     print "Could not detect character encoding."
     CHARMAP = "ASCII"
