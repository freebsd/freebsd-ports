--- __init__.py.bak	Sun Mar 21 17:40:07 2004
+++ __init__.py	Sun Mar 21 17:41:40 2004
@@ -21,7 +21,7 @@
 		self._set_config_type("update", TYPE_INT, int(interval))
 		self._set_config_type("format", TYPE_STRING, format)
 		self._set_config_type("host", TYPE_STRING, commands.getoutput("uname -n"))
-		self._set_config_type("os", TYPE_STRING, commands.getoutput("uname -o"))
+		self._set_config_type("os", TYPE_STRING, commands.getoutput("uname -s"))
 		self._set_config_type("kernel", TYPE_STRING, commands.getoutput("uname -s"))
 		self._set_config_type("version", TYPE_STRING, commands.getoutput("uname -r"))
 		self._set_config_type("processor", TYPE_STRING, commands.getoutput("uname -p"))
