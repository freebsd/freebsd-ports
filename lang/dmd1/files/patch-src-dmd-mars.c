--- ../../src/dmd/mars.c.orig	2012-12-31 12:16:46.000000000 -0800
+++ ../../src/dmd/mars.c	2013-09-27 11:06:20.705469255 -0700
@@ -387,7 +387,7 @@
 }
 #endif
 
-int main(size_t argc, char *argv[])
+int main(int argc, char *argv[])
 {
     mem.init();                         // initialize storage allocator
     mem.setStackBottom(&argv);
@@ -422,7 +422,7 @@
             goto Largs;
     }
 
-    if (response_expand(&argc,&argv))   // expand response files
+    if (response_expand((size_t *) &argc,&argv))   // expand response files
         error(0, "can't open response file");
 
     files.reserve(argc - 1);
@@ -522,7 +522,7 @@
 
     inifile(argv[0], inifilename, is64bit ? "Environment64" : "Environment32");
 
-    getenv_setargv("DFLAGS", &argc, &argv);
+    getenv_setargv("DFLAGS", (size_t *) &argc, &argv);
 
 #if 0
     for (size_t i = 0; i < argc; i++)
