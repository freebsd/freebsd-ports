
$FreeBSD$

--- Moleskine/MoleskineApp.py	2001/01/12 14:58:39	1.1
+++ Moleskine/MoleskineApp.py	2001/01/12 14:58:55
@@ -38,7 +38,7 @@
         
         self.set_wmclass('main_window', 'Moleskine')
         self.connect('delete_event', menu.exit)
-        self.set_usize(830, 670)
+        self.set_usize(630, 470)
         self.set_contents(self.notebook)
         
         self.create_menus(menu.main_menu)
