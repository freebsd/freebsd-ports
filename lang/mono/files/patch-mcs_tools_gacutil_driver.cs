
$FreeBSD$

--- mcs/tools/gacutil/driver.cs.orig
+++ mcs/tools/gacutil/driver.cs
@@ -427,15 +427,33 @@
 					break;
 
 				string dir = directories [i];
+				string extension = null;
+				
+				if (File.Exists(Path.Combine (dir, assembly_name + ".dll"))) {
+					extension = ".dll";
+				} else if (File.Exists(Path.Combine (dir, assembly_name + ".DLL"))) {
+					extension = ".DLL";
+				} else if (File.Exists(Path.Combine (dir, assembly_name + ".exe"))) {
+					extension = ".exe";
+				} else if (File.Exists(Path.Combine (dir, assembly_name + ".EXE"))) {
+					extension = ".EXE";
+				} else {
+					failures++;
+					WriteLine("Cannot find the assembly: " + assembly_name);
+					continue;
+				}
+
+				string AssemblyFilename = assembly_name + extension;
 
 				AssemblyName an = AssemblyName.GetAssemblyName (
-					Path.Combine (dir, assembly_name + ".dll"));
+					Path.Combine(dir, AssemblyFilename));
 				WriteLine ("Assembly: " + an.FullName);
 
 				Directory.Delete (dir, true);
 				if (package != null) {
 					string link_dir = Path.Combine (libdir, package);
-					string link = Path.Combine (link_dir, assembly_name + ".dll");
+					string link = Path.Combine(link_dir, AssemblyFilename);
+
 					try { 
 						File.Delete (link);
 					} catch {
