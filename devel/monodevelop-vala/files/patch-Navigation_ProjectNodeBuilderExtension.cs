
$FreeBSD$

--- Navigation/ProjectNodeBuilderExtension.cs.orig
+++ Navigation/ProjectNodeBuilderExtension.cs
@@ -100,7 +100,7 @@
 			check_ctags = true;
 			
 			try {
-				ProcessWrapper p = Runtime.ProcessService.StartProcess ("ctags", "--version", null, null);
+				ProcessWrapper p = Runtime.ProcessService.StartProcess ("exctags", "--version", null, null);
 				p.WaitForOutput ();
 				have_ctags = true;
 			} catch {
