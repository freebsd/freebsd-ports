--- src/emu/cpu/tms57002/tmsmake.py.orig
+++ src/emu/cpu/tms57002/tmsmake.py
@@ -328,7 +328,7 @@
 def LoadLst(filename):
     instructions = []
     ins = None
-    for n, line in enumerate(open(filename)):
+    for n, line in enumerate(open(filename, "rU")):
         line = line.rstrip()
         if not line and ins:
             # new lines separate intructions
