--- __init__.py.bak	Sun Mar 28 15:47:22 2004
+++ __init__.py	Sun Mar 28 15:47:55 2004
@@ -126,7 +126,10 @@
 		timezone = self._get_config("timezone")
 		if timezone != self.__timezone:
 			self.__timezone = timezone
-			offset = commands.getoutput("TZ=\"%(timezone)s\" date +%%z" % vars())
+			if timezone == "localtime":
+				offset = commands.getoutput("date +%z")
+			else:
+				offset = commands.getoutput("TZ=\"%(timezone)s\" date +%%z" % vars())
 			sign = (offset[0] == "+") and 1 or -1
 			hours = int(offset[1:3])
 			mins = int(offset[3:5])
