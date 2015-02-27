--- ../../src/dmd/link.c.orig	2014-10-15 19:23:32.000000000 -0700
+++ ../../src/dmd/link.c	2015-02-24 16:12:51.633410115 -0800
@@ -446,7 +446,7 @@
 
     const char *cc = getenv("CC");
     if (!cc)
-        cc = "gcc";
+        cc = "cc";
     argv.push(cc);
     argv.insert(1, global.params.objfiles);
 
