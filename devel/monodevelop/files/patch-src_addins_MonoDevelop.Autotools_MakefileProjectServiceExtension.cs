--- src/addins/MonoDevelop.Autotools/MakefileProjectServiceExtension.cs.orig
+++ src/addins/MonoDevelop.Autotools/MakefileProjectServiceExtension.cs
@@ -168,7 +168,7 @@
 				chainedOutput.ChainWriter (monitor.Log);
 				chainedOutput.ChainWriter (swOutput);
 
-				ProcessWrapper process = Runtime.ProcessService.StartProcess ("make",
+				ProcessWrapper process = Runtime.ProcessService.StartProcess ("gmake",
 						args,
 						baseDir, 
 						chainedOutput, 
@@ -254,7 +254,7 @@
 		// Snatched from our codedom code :-).
 		//FIXME: Get this from the language binding.. if a known lang
 
-		static Regex regexEnterDir = new Regex (@"make\[[0-9]*\]: ([a-zA-Z]*) directory `(.*)'");
+		static Regex regexEnterDir = new Regex (@"gmake\[[0-9]*\]: ([a-zA-Z]*) directory `(.*)'");
 		
 		private static CompilerError CreateCompilerErrorFromString (string error_string, Stack<string> dirs, Regex regex)
 		{
@@ -280,7 +280,7 @@
 				return null;
 			}
 
-			if (error_string.StartsWith ("make"))
+			if (error_string.StartsWith ("gmake"))
 				return null;
 
 			match = regex.Match (error_string);
@@ -345,7 +345,7 @@
 			{
 				string baseDir = proj.BaseDirectory;
 	
-				ProcessWrapper process = Runtime.ProcessService.StartProcess ( "make", 
+				ProcessWrapper process = Runtime.ProcessService.StartProcess ( "gmake", 
 						data.CleanTargetName,
 						baseDir, 
 						monitor.Log, 
@@ -354,7 +354,7 @@
 				process.WaitForOutput ();
 
 				if ( process.ExitCode > 0 )
-					throw new Exception ( GettextCatalog.GetString ("An unspecified error occurred while running '{0}'", "make " + data.CleanTargetName) );
+					throw new Exception ( GettextCatalog.GetString ("An unspecified error occurred while running '{0}'", "gmake " + data.CleanTargetName) );
 
 				monitor.Step ( 1 );
 			}
@@ -400,7 +400,7 @@
 			monitor.BeginTask (GettextCatalog.GetString ("Executing {0}", project.Name), 1);
 			try
 			{
-				ProcessWrapper process = Runtime.ProcessService.StartProcess ("make",
+				ProcessWrapper process = Runtime.ProcessService.StartProcess ("gmake",
 						data.ExecuteTargetName,
 						project.BaseDirectory,
 						console.Out,
