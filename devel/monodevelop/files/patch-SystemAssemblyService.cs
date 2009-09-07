
$FreeBSD$

--- src/core/MonoDevelop.Core/MonoDevelop.Core/SystemAssemblyService.cs.orig
+++ src/core/MonoDevelop.Core/MonoDevelop.Core/SystemAssemblyService.cs
@@ -412,6 +412,7 @@
 			
 			string[] suffixes = new string [] {
 				Path.Combine ("lib", "pkgconfig"),
+				Path.Combine ("libdata", "pkgconfig"),
 				Path.Combine ("lib64", "pkgconfig"),
 				Path.Combine ("share", "pkgconfig"),
 			};
