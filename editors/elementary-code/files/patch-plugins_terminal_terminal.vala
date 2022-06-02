--- plugins/terminal/terminal.vala.orig	2022-04-04 16:20:49 UTC
+++ plugins/terminal/terminal.vala
@@ -200,13 +200,16 @@ public class Scratch.Plugins.Terminal : Peas.Extension
 
     public string get_shell_location () {
         int pid = (!) (this.child_pid);
+        string cwd = "";
 
         try {
-            return GLib.FileUtils.read_link ("/proc/%d/cwd".printf (pid));
+            //return GLib.FileUtils.read_link ("/proc/%d/cwd".printf (pid));
+            GLib.Process.spawn_command_line_sync ("pwd", out cwd);
         } catch (GLib.FileError error) {
             warning ("An error occurred while fetching the current dir of shell");
-            return "";
         }
+
+        return cwd;
     }
 
     void on_hook_notebook () {
