--- src/Widgets/Terminal.vala.orig	2023-01-24 16:59:41 UTC
+++ src/Widgets/Terminal.vala
@@ -87,13 +87,14 @@ public class Code.Terminal : Gtk.Box {
     }
 
     private string get_shell_location () {
-        int pid = (!) (this.child_pid);
+        string cwd = "";
         try {
-            return GLib.FileUtils.read_link ("/proc/%d/cwd".printf (pid));
+            GLib.Process.spawn_command_line_sync ("pwd", out cwd);
         } catch (GLib.FileError error) {
             warning ("An error occurred while fetching the current dir of shell: %s", error.message);
-            return "";
         }
+
+        return cwd;
     }
 
     private void update_terminal_settings (string settings_schema) {
