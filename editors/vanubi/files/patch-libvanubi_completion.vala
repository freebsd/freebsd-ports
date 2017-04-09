--- libvanubi/completion.vala.orig	2015-07-03 10:10:29 UTC
+++ libvanubi/completion.vala
@@ -21,11 +21,11 @@ namespace Vanubi {
 	public class AbbrevCompletion {
 		LRU<string> lru = new LRU<string> (strcmp);
 		Annotated<string>[] tags = null;
-		Regex regex;
+		GLib.Regex regex;
 
 		public AbbrevCompletion () {
 			try {
-				regex = new Regex ("\\w+", RegexCompileFlags.MULTILINE | RegexCompileFlags.OPTIMIZE);
+				regex = new GLib.Regex ("\\w+", GLib.RegexCompileFlags.MULTILINE | GLib.RegexCompileFlags.OPTIMIZE);
 			} catch (Error e) {
 				warning (e.message);
 			}
