--- pyxmame/Config.py	Mon Jul  3 15:31:07 2006
+++ pyxmame/Config.py	Tue Aug  1 03:45:45 2006
@@ -3,8 +3,9 @@
 
 import re
 import os
+import sys
 
-CONFIG_FILE="/etc/pyxmame/pyxmamerc"
+CONFIG_FILE=sys.prefix+"/etc/pyxmame/pyxmamerc"
 HOME_FILE=os.environ['HOME']+"/.pyxmame/pyxmamerc"
 
 class Config(dict):
