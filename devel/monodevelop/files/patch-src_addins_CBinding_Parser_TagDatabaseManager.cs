
$FreeBSD$

--- src/addins/CBinding/Parser/TagDatabaseManager.cs.orig
+++ src/addins/CBinding/Parser/TagDatabaseManager.cs
@@ -86,7 +86,7 @@
 						return false;
 					}
 					try {
-						Runtime.ProcessService.StartProcess ("ctags", "--version", null, null).WaitForOutput ();
+						Runtime.ProcessService.StartProcess ("exctags", "--version", null, null).WaitForOutput ();
 					} catch {
 						LoggingService.LogWarning ("Cannot update C/C++ tags database because exuberant ctags is not installed.");
 						return false;
@@ -276,7 +276,7 @@
 				try {
 					output = new System.IO.StringWriter ();
 					
-					p = Runtime.ProcessService.StartProcess ("ctags", ctags_options, null, null, output, null);
+					p = Runtime.ProcessService.StartProcess ("exctags", ctags_options, null, null, output, null);
 					p.WaitForOutput (10000);
 					if (p.ExitCode != 0 || !File.Exists (tagFullFileName)) {
 						LoggingService.LogError ("Ctags did not successfully populate the tags database '{0}' within ten seconds.\nOutput: {1}", tagFullFileName, output.ToString ());
@@ -383,7 +383,7 @@
 				output = new System.IO.StringWriter ();
 				error = new System.IO.StringWriter ();
 				
-				p = Runtime.ProcessService.StartProcess ("ctags", ctags_kinds.ToString (), project.BaseDirectory, output, error, null);
+				p = Runtime.ProcessService.StartProcess ("exctags", ctags_kinds.ToString (), project.BaseDirectory, output, error, null);
 				p.WaitForOutput (10000);
 				if (p.ExitCode != 0) {
 					LoggingService.LogError ("Ctags did not successfully populate the tags database from '{0}' within ten seconds.\nError output: {1}", filename, error.ToString ());
