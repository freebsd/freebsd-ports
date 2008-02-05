--- src/freera.cpp.orig	2007-04-20 00:35:26.000000000 +0400
+++ src/freera.cpp	2008-02-05 02:42:33.000000000 +0300
@@ -58,8 +58,8 @@
     }
 
     const string& binpath = determineBinaryLocation(argv[0]);
-    string lf(binpath);
-    lf += "/freera.log";
+    string lf(getenv("HOME"));
+    lf += "/.freera.log";
 
     VFS_PreInit(binpath.c_str());
     // Log level is so that only errors are shown on stdout by default
