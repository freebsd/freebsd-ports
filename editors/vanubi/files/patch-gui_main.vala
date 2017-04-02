--- gui/main.vala.orig	2015-07-03 10:10:29 UTC
+++ gui/main.vala
@@ -35,12 +35,12 @@ namespace Vanubi.UI {
 			{ null }
 		};
 
-		static Regex file_pos_regex = null;
+		static GLib.Regex file_pos_regex = null;
 		
 		static construct {
 			try {
 				var file_pos = """^(?<f>.+?)(?::(?<sl>\d+)(?::(?<sc>\d+))?)?$""";
-				file_pos_regex = new Regex (file_pos, RegexCompileFlags.CASELESS|RegexCompileFlags.OPTIMIZE);
+				file_pos_regex = new GLib.Regex (file_pos, GLib.RegexCompileFlags.CASELESS|GLib.RegexCompileFlags.OPTIMIZE);
 			} catch (Error e) {
 				error (e.message);
 			}
