--- StarterBar/__init__.py.orig	Wed Sep 24 14:31:33 2003
+++ StarterBar/__init__.py	Wed Sep 24 14:32:22 2003
@@ -336,7 +336,7 @@
             index = self.__current_index
             if (self.__dragged_icon == -1 or self.__dragged_icon == index):
                 cmd = self.__icon_set.get_icon(index).get_command()
-                os.system("cd ~ && " + cmd + " & disown")
+                os.system("cd ~ && " + cmd + " &")
                 self.__animator.unhilight()
                 if (self._get_config("animation")):
                     self.__animator.jump(index)
