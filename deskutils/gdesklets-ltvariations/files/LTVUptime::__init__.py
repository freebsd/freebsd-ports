--- __init__.py.bak	Fri Mar 26 22:08:26 2004
+++ __init__.py	Fri Mar 26 22:08:49 2004
@@ -21,7 +21,7 @@
 		self._set_config_type("update", TYPE_INT, int(interval))
 		self._set_config_type("format", TYPE_STRING, format)
 		self._set_config_type("host", TYPE_STRING, commands.getoutput("uname -n"))
-		self._set_config_type("os", TYPE_STRING, commands.getoutput("uname -o"))
+		self._set_config_type("os", TYPE_STRING, commands.getoutput("uname -s"))
 		self._set_config_type("kernel", TYPE_STRING, commands.getoutput("uname -s"))
 		self._set_config_type("version", TYPE_STRING, commands.getoutput("uname -r"))
 		self._set_config_type("processor", TYPE_STRING, commands.getoutput("uname -p"))
@@ -63,7 +63,7 @@
 
 	def draw_uptime(self, data):
 		if self.__enable[ 0 ] != "0" :
-			uptime = float( commands.getoutput("cat /proc/uptime").split()[0] )
+			uptime = time.time() - float(commands.getoutput("sysctl kern.boottime").split()[4][:-1])
 			d = int( uptime / 60 / 60 / 24 )
 			uptime = uptime - d * 60 * 60 * 24
 			h = int( uptime / 60 / 60 )
