--- StarterBar/__init__.py.orig	Sun Nov  9 16:16:45 2003
+++ StarterBar/__init__.py	Sun Nov  9 16:16:59 2003
@@ -413,7 +413,7 @@
         cmd = self.__icon_set.get_icon(index).get_command()
         cmd = cmd.replace("%U", file)
 
-        os.system("cd ~ && " + cmd + " & disown")
+        os.system("cd ~ && " + cmd + " &")
         self.__animator.unhilight()
         if (self._get_config("animation")):
             self.__animator.jump(index)
