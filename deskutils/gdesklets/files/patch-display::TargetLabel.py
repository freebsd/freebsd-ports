--- display/TargetLabel.py.orig	Tue Dec 30 13:26:48 2003
+++ display/TargetLabel.py	Tue Dec 30 13:27:20 2003
@@ -90,7 +90,14 @@
 
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
