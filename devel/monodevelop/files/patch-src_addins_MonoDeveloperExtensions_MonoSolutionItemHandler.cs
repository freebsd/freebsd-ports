--- src/addins/MonoDeveloperExtensions/MonoSolutionItemHandler.cs.orig
+++ src/addins/MonoDeveloperExtensions/MonoSolutionItemHandler.cs
@@ -185,7 +185,7 @@
 			tw.ChainWriter (output);
 			tw.ChainWriter (monitor.Log);
 			
-			ProcessWrapper proc = Runtime.ProcessService.StartProcess ("make", "PROFILE=" + conf.Id + " " + target, conf.OutputDirectory, monitor.Log, tw, null);
+			ProcessWrapper proc = Runtime.ProcessService.StartProcess ("gmake", "PROFILE=" + conf.Id + " " + target, conf.OutputDirectory, monitor.Log, tw, null);
 			proc.WaitForOutput ();
 			
 			CompilerResults cr = new CompilerResults (null);			
@@ -202,7 +202,7 @@
 		{
 			// When IncludeDebugInformation is true, prevents the debug symbols stats from braeking this.
 			if (error_string.StartsWith ("WROTE SYMFILE") ||
-			    error_string.StartsWith ("make[") ||
+			    error_string.StartsWith ("gmake[") ||
 			    error_string.StartsWith ("OffsetTable") ||
 			    error_string.StartsWith ("Compilation succeeded") ||
 			    error_string.StartsWith ("Compilation failed"))
