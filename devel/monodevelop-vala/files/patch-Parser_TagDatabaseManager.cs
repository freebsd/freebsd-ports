
$FreeBSD$

--- Parser/TagDatabaseManager.cs.orig
+++ Parser/TagDatabaseManager.cs
@@ -81,7 +81,7 @@
 						return false;
 					}
 					try {
-						Runtime.ProcessService.StartProcess ("ctags", "--version", null, null).WaitForOutput ();
+						Runtime.ProcessService.StartProcess ("exctags", "--version", null, null).WaitForOutput ();
 					} catch {
 						LoggingService.LogWarning ("Cannot update Vala tags database because exuberant ctags is not installed.");
 						return false;
@@ -254,7 +254,7 @@
 				try {
 					output = new System.IO.StringWriter ();
 					
-					p = Runtime.ProcessService.StartProcess ("ctags", ctags_options, null, output, output, null);
+					p = Runtime.ProcessService.StartProcess ("exctags", ctags_options, null, output, output, null);
 					p.WaitForOutput (10000);
 					if (p.ExitCode != 0 || !File.Exists (tagFullFileName)) {
 						LoggingService.LogError ("Ctags did not successfully populate the tags database '{0}' from '{1}' within ten seconds.\nOutput: {2}", tagFullFileName, output.ToString ());
@@ -345,7 +345,7 @@
 			try {
 				output = new System.IO.StringWriter ();
 				error = new System.IO.StringWriter ();
-				p = Runtime.ProcessService.StartProcess ("ctags", ctags_options, null, output, error, null);
+				p = Runtime.ProcessService.StartProcess ("exctags", ctags_options, null, output, error, null);
 				p.WaitForOutput (10000);
 				if (p.ExitCode != 0) {
 					LoggingService.LogError ("Ctags did not successfully populate the tags database from '{0}' within ten seconds.\nError output: {1}", filename, error.ToString ());
