Add support of vte-2.91 instead of vte-2.90

--- gui/shellbar.vala.orig	2015-07-03 10:10:29 UTC
+++ gui/shellbar.vala
@@ -29,8 +29,8 @@ namespace Vanubi.UI {
 		Cancellable pty_cancellable;
 		bool is_first_line = true;
 		
-		static Regex error_regex = null;
-		static Regex dir_regex = null;
+		static GLib.Regex error_regex = null;
+		static GLib.Regex dir_regex = null;
 		
 		static construct {
 			try {
@@ -44,11 +44,11 @@ namespace Vanubi.UI {
 				var php_error = """^(?<msg>.+)error:.* in (?<f>.+) on line (?<sl>\d+)\s*$""";
 				// sh style
 				var sh_error = """^(?<f>.+?):.*?(?<sl>\d+?):.*?:(?<msg>.*? error):""";
-				error_regex = new Regex (@"(?:$(vala_error))|(?:$(php_error))|(?:$(c_error))|(?:$(sh_error))|(?:$(java_error))", RegexCompileFlags.CASELESS|RegexCompileFlags.OPTIMIZE|RegexCompileFlags.DUPNAMES);
+				error_regex = new GLib.Regex (@"(?:$(vala_error))|(?:$(php_error))|(?:$(c_error))|(?:$(sh_error))|(?:$(java_error))", GLib.RegexCompileFlags.CASELESS|GLib.RegexCompileFlags.OPTIMIZE|GLib.RegexCompileFlags.DUPNAMES);
 				
 				// enter directory
 				var make_dir = """^.*Entering directory `(.+?)'.*$""";
-				dir_regex = new Regex (@"(?:$(make_dir))", RegexCompileFlags.CASELESS|RegexCompileFlags.OPTIMIZE|RegexCompileFlags.DUPNAMES);
+				dir_regex = new GLib.Regex (@"(?:$(make_dir))", GLib.RegexCompileFlags.CASELESS|GLib.RegexCompileFlags.OPTIMIZE|GLib.RegexCompileFlags.DUPNAMES);
 			} catch (Error e) {
 				error (e.message);
 			}
@@ -146,10 +146,10 @@ namespace Vanubi.UI {
 				}
 
 				Pid pid;
-				term.fork_command_full (PtyFlags.DEFAULT, workdir, {shell}, null, SpawnFlags.SEARCH_PATH, null, out pid);
+				term.spawn_sync (PtyFlags.DEFAULT, workdir, {shell}, null, SpawnFlags.SEARCH_PATH, null, out pid);
 				term.set_data ("pid", pid);
 				pty_cancellable = new Cancellable ();
-				read_sh.begin (term.pty_object.fd, pty_cancellable);
+				read_sh.begin (term.get_pty ().fd, pty_cancellable);
 
 				mouse_match (term, """^.+error:""");
 				mouse_match (term, """^.+warning:""");
@@ -255,10 +255,10 @@ namespace Vanubi.UI {
 		
 		private void mouse_match (Terminal t, string str) {
 			try {
-				var regex = new Regex (str);
+				var regex = new GLib.Regex (str);
 				int id = t.match_add_gregex (regex, 0);
 				t.match_set_cursor_type (id, Gdk.CursorType.HAND2);
-			} catch (RegexError e) {
+			} catch (GLib.RegexError e) {
 				warning (e.message);
 			}
 		}
