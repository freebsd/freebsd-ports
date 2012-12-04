--- glob/glob1.cc.orig	2012-10-27 10:28:31.000000000 +0200
+++ glob/glob1.cc	2012-12-02 01:08:36.000000000 +0100
@@ -1,6 +1,6 @@
 #include "glob.ih"
 
 Glob::Glob(string const &pattern, int flags, Dots dots)
-:
-    Glob(ANY, pattern, flags, dots)
-{}
+{
+    Glob(ANY, pattern, flags, dots);
+}
