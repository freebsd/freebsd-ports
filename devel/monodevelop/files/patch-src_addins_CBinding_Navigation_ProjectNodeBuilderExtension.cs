
$FreeBSD$

--- src/addins/CBinding/Navigation/ProjectNodeBuilderExtension.cs.orig
+++ src/addins/CBinding/Navigation/ProjectNodeBuilderExtension.cs
@@ -97,7 +97,7 @@
 			check_ctags = true;
 			
 			try {
-				ProcessWrapper p = Runtime.ProcessService.StartProcess ("ctags", "--version", null, null);
+				ProcessWrapper p = Runtime.ProcessService.StartProcess ("exctags", "--version", null, null);
 				p.WaitForOutput ();
 				have_ctags = true;
 			} catch {
