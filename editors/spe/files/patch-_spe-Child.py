--- _spe/Child.py	Thu Jan 26 04:58:19 2006
+++ _spe/Child.py.port	Thu Jan 11 22:50:43 2007
@@ -526,14 +526,14 @@
             elif os.path.isfile('/usr/bin/gnome-terminal'):
                 os.system('/usr/bin/gnome-terminal --title SPE --working-directory="%(path)s" &')
             else:
-                os.system('cd %(path)s;xterm &')
+                os.system('cd %s;xterm &' %(path))
         else:
             os.system(terminal%params)
 
     def run(self):
         if not self.confirmSave():
             return
-        from _spe.dialogs.runTerminalDialog import RunTerminalDialog
+        from _spe.dialogs.RunTerminalDialog import RunTerminalDialog
         runTerminalDialog   = RunTerminalDialog(self.fileName,
                                 self.argumentsPrevious,
                                 self.inspectPrevious,
