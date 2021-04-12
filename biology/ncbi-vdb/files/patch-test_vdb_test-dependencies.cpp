--- test/vdb/test-dependencies.cpp.orig	2019-08-20 18:27:10 UTC
+++ test/vdb/test-dependencies.cpp
@@ -115,7 +115,7 @@ class EmptyFixture : public DepFixture { (public)
 
 class RefseqFixture : public DepFixture {
 
-  #if LINUX
+  #if LINUX || BSD
     #define PATH "kfg/linux"
   #elif MAC
     #define PATH "kfg/mac"
