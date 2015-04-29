--- virtManager/serialcon.py.orig	2014-07-28 15:11:32 UTC
+++ virtManager/serialcon.py
@@ -326,7 +326,6 @@ class vmmSerialConsole(vmmGObject):
         self.terminal = Vte.Terminal()
         self.terminal.set_scrollback_lines(1000)
         self.terminal.set_audible_bell(False)
-        self.terminal.set_visible_bell(True)
 
         self.terminal.connect("button-press-event", self.show_serial_rcpopup)
         self.terminal.connect("commit", self.console.send_data, self.terminal)
