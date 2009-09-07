
$FreeBSD$

--- src/addins/MonoDevelop.Autotools/SolutionDeployer.cs.orig
+++ src/addins/MonoDevelop.Autotools/SolutionDeployer.cs
@@ -171,7 +171,7 @@
 				chainedOutput.ChainWriter (monitor.Log);
 				chainedOutput.ChainWriter (sw);
 
-				ProcessWrapper process = Runtime.ProcessService.StartProcess ( "make", 
+				ProcessWrapper process = Runtime.ProcessService.StartProcess ( "gmake", 
 						"dist", 
 						baseDir, 
 						chainedOutput, 
@@ -180,7 +180,7 @@
 				process.WaitForOutput ();
 
 				if ( process.ExitCode > 0 )
-					throw new Exception ( GettextCatalog.GetString ("An unspecified error occurred while running '{0}'", "make dist") );
+					throw new Exception ( GettextCatalog.GetString ("An unspecified error occurred while running '{0}'", "gmake dist") );
 
 				monitor.Step ( 1 );
 
