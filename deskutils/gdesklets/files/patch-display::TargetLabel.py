--- display/TargetLabel.py.orig	Sat Oct 25 02:15:56 2003
+++ display/TargetLabel.py	Sat Oct 25 02:21:05 2003
@@ -76,7 +76,14 @@
 
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
