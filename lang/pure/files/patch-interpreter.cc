--- interpreter.cc.orig	2010-11-08 02:57:58.000000000 -0600
+++ interpreter.cc	2011-03-19 02:01:57.145664585 -0500
@@ -6709,6 +6709,11 @@ int interpreter::compiler(string out, li
   // Compile and link, if requested.
   if (target != out) {
     assert(bc_target);
+    string cc = "gcc";
+    string cxx = "g++";
+    const char *env;
+    if (env = getenv("CC")) cc = env;
+    if (env = getenv("CXX")) cxx = env;
     bool vflag = (verbose&verbosity::compiler) != 0;
     string libs;
     set<string> libset;
@@ -6735,7 +6740,7 @@ int interpreter::compiler(string out, li
     if (WIFEXITED(status) && WEXITSTATUS(status) == 0 && ext!=".s") {
       // Assemble.
       string obj = (ext==".o")?out:out+".o";
-      cmd = "gcc -c "+quote(asmfile)+" -o "+quote(obj);
+      cmd = cc+" -c "+quote(asmfile)+" -o "+quote(obj);
       if (vflag) std::cerr << cmd << '\n';
       status = system(cmd.c_str());
       unlink(asmfile.c_str());
@@ -6755,7 +6760,7 @@ int interpreter::compiler(string out, li
 	  " -lpure";
 	if (ext != ".o") {
 	  // Link.
-	  cmd = "g++ -o "+quote(out)+" "+quote(libdir)+"pure_main.o "+linkopts;
+	  cmd = cxx+" -o "+quote(out)+" "+quote(libdir)+"pure_main.o "+linkopts;
 	  if (vflag) std::cerr << cmd << '\n';
 	  status = system(cmd.c_str());
 	  unlink(obj.c_str());
