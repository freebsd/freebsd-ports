compiling failed, log:
0:2(1): preprocessor error: #version must appear on the first line

--- src/shader.cpp.orig	2020-03-29 17:02:18 UTC
+++ src/shader.cpp
@@ -74,6 +74,8 @@ glsl_shader::glsl_shader(const string& filename, type 
 		// the program as string
 		string prg;
 
+		prg += "#version 110\n";
+
 		// add defines to top of list for preprocessor
 		for (defines_list::const_iterator it = dl.begin(); it != dl.end(); ++it) {
 			prg += string("#define ") + *it + "\n";
@@ -83,7 +85,10 @@ glsl_shader::glsl_shader(const string& filename, type 
 		while (!ifprg.eof()) {
 			string s;
 			getline(ifprg, s);
-			prg += s + "\n";
+			string prefix("#version");
+			if (0 != s.compare(0, prefix.size(), prefix)) {
+				prg += s + "\n";
+			}
 		}
 
 		const char* prg_cstr = prg.c_str();
