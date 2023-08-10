--- ncbi-vdb/test/vdb/test-dependencies_dflt.cpp.orig	2023-07-10 16:13:36 UTC
+++ ncbi-vdb/test/vdb/test-dependencies_dflt.cpp
@@ -139,6 +139,9 @@ class EmptyFixture : public DepFixture { (public)
 
 class RefseqFixture : public DepFixture {
 
+  #if BSD
+    // FIXME: Should there be a separate kfg/freebsd?
+    #define PATH "kfg/linux"
   #if LINUX
     #define PATH "kfg/linux"
   #elif MAC
