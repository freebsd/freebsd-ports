--- ide-integration/BicycleRepairMan_Idle.py.orig	Wed Jul 20 00:48:43 2005
+++ ide-integration/BicycleRepairMan_Idle.py	Wed Jul 20 00:51:46 2005
@@ -300,21 +300,20 @@
         return 1
 
 
-    def confirm_buffer_is_saved(self, editwin):
-        if not editwin.get_saved():
-            name = (editwin.short_title()or
-            editwin.long_title()or
-            "Untitled")
-            reply = tkMessageBox.askokcancel("Bicycle Repair Man",
-                "The buffer for %s is not saved.\n\n"%name+
-                "Save it and continue?",
-                master = self.editwin.text)
-          &nbs p; self.editwin.text.focus_set()
-            if reply:
-                editwin.io.save(None)
-            else:
-                return 0
-        return 1
+	def confirm_buffer_is_saved(self, editwin):
+			if not editwin.get_saved():
+				name = (editwin.short_title()or
+				editwin.long_title()or "Untitled")
+			reply = tkMessageBox.askokcancel("Bicycle Repair Man",
+			"The buffer for %s is not saved.\n\n"%name+
+			"Save it and continue?",
+			master = self.editwin.text)
+			self.editwin.text.focus_set()
+			if reply:
+				editwin.io.save(None)
+			else:
+				return 0
+			return 1
 
     def errorbox(self, title, message):
         tkMessageBox.showerror(title, message, master = self.editwin.text)
