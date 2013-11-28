--- ./scanner/scanner1.cc.orig	2013-06-23 20:13:49.000000000 +0200
+++ ./scanner/scanner1.cc	2013-11-27 19:03:33.000000000 +0100
@@ -15,7 +15,7 @@
 
     string value;
     if (arg.option(&value, "max-inclusion-depth"))
-        d_maxDepth = stoul(value);
+        d_maxDepth = A2x(value);
     else
         d_maxDepth = 10;
 }
