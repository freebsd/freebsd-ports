--- StarterBar/__init__.py.orig	Fri Jun 25 00:28:11 2004
+++ StarterBar/__init__.py	Fri Jun 25 00:31:02 2004
@@ -572,7 +572,7 @@
         cmd = self.__icon_set.get_icon(index).get_command()
         cmd = cmd.replace("%U", file)
 
-        os.system("cd ~ && exec " + cmd + " & disown")
+        os.system("cd ~ && exec " + cmd + " &")
 
 
     #
