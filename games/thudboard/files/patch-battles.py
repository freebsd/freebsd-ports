--- battle.py.orig	Tue Jan 13 17:49:47 2004
+++ battle.py	Tue Jan 13 17:50:54 2004
@@ -411,9 +411,9 @@
         filename = self.filename
         if not filename: 
             filename = self.name
-            filename = os.sep.join([os.getcwd(), "battles", filename+".thud"])
+            filename = os.sep.join(["~/.thudboard/", "battles", filename+".thud"])
         if not self.name or filename=='<anonymous battle>': 
-            filename = os.sep.join([os.getcwd(), "battles", ""])
+            filename = os.sep.join(["~/.thudboard/", "battles", ""])
         return filename
 
 #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
