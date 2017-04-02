--- libvanubi/util.vala.orig	2015-07-03 10:10:29 UTC
+++ libvanubi/util.vala
@@ -35,12 +35,12 @@ namespace Vanubi {
 		public int end_line;
 		public int end_column;
 
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
@@ -181,15 +181,15 @@ namespace Vanubi {
 	
 	public async extern void spawn_async_with_pipes (string? working_directory, [CCode (array_length = false, array_null_terminated = true)] string[] argv, [CCode (array_length = false, array_null_terminated = true)] string[]? envp, SpawnFlags _flags, SpawnChildSetupFunc? child_setup, int io_priority, Cancellable? cancellable, out Pid child_pid, out int standard_input = null, out int standard_output = null, out int standard_error = null) throws SpawnError;
 	
-	static Regex update_copyright_year_regex1 = null;
-	static Regex update_copyright_year_regex2 = null;
+	static GLib.Regex update_copyright_year_regex1 = null;
+	static GLib.Regex update_copyright_year_regex2 = null;
 	
 	// Returns true if any copyright year has been replaced
 	public bool update_copyright_year (Buffer buf) {
 		if (update_copyright_year_regex1 == null || update_copyright_year_regex2 == null) {
 			try {
-				update_copyright_year_regex1 = new Regex ("Copyright.*\\d\\d\\d\\d-(\\d\\d\\d\\d)", RegexCompileFlags.OPTIMIZE | RegexCompileFlags.CASELESS);
-				update_copyright_year_regex2 = new Regex ("Copyright.*(\\d\\d\\d\\d)", RegexCompileFlags.OPTIMIZE | RegexCompileFlags.CASELESS);
+				update_copyright_year_regex1 = new GLib.Regex ("Copyright.*\\d\\d\\d\\d-(\\d\\d\\d\\d)", GLib.RegexCompileFlags.OPTIMIZE | GLib.RegexCompileFlags.CASELESS);
+				update_copyright_year_regex2 = new GLib.Regex ("Copyright.*(\\d\\d\\d\\d)", GLib.RegexCompileFlags.OPTIMIZE | GLib.RegexCompileFlags.CASELESS);
 			} catch (Error e) {
 				warning (e.message);
 				return false;
