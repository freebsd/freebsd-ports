--- gui/searchbar.vala.orig	2015-07-03 10:10:29 UTC
+++ gui/searchbar.vala
@@ -153,11 +153,11 @@ namespace Vanubi.UI {
 				// do not parse in case of any error during parsing or evaluating the expression
 			}
 			
-			Regex regex = null;
+			GLib.Regex regex = null;
 			if (is_regex) {
 				try {
 					state.status.clear ("search");
-					regex = new Regex (p, RegexCompileFlags.OPTIMIZE, RegexMatchFlags.ANCHORED);
+					regex = new GLib.Regex (p, GLib.RegexCompileFlags.OPTIMIZE, GLib.RegexMatchFlags.ANCHORED);
 				} catch (Error e) {
 					// user still writing regex, display an error
 					state.status.set (e.message, "search", Status.Type.ERROR);
@@ -381,4 +381,4 @@ namespace Vanubi.UI {
 			return base.on_key_press_event (e);
 		}
 	}
-}
\ No newline at end of file
+}
