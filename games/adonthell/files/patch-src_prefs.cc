--- src/prefs.cc.orig	2007-11-21 17:58:31.000000000 +0100
+++ src/prefs.cc	2007-11-21 17:58:43.000000000 +0100
@@ -144,7 +144,7 @@
             case 'c':
             {
                 python::init (); 
-                python::exec_string ("import compileall; compileall.compile_dir (\".\", 0);");  
+                python::exec_string ((char *)"import compileall; compileall.compile_dir (\".\", 0);");  
                 python::cleanup (); 
                 exit (0); 
                 break;
