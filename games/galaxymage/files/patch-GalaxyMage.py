--- GalaxyMage.py.old	Mon Jan 30 20:13:39 2006
+++ GalaxyMage.py	Mon Jan 30 20:13:51 2006
@@ -23,7 +23,7 @@
 import os, sys
 if os.path.isdir(sys.path[0]):
     os.chdir(sys.path[0])
-sys.path.append("src")
+sys.path.append("%%DATADIR%%")
 
 import Main
 
