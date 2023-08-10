--- ncbi-vdb/test/kfg/kfgtest.cpp.orig	2023-07-10 16:13:36 UTC
+++ ncbi-vdb/test/kfg/kfgtest.cpp
@@ -282,6 +282,8 @@ FIXTURE_TEST_CASE(predef_ARCHBITS, KfgFixture)
 FIXTURE_TEST_CASE(predef_OS, KfgFixture)
 {
     CreateAndLoad(GetName(), "var=$(OS)\n");
+    #if BSD
+        #define OS "bsd"
     #if LINUX
         #define OS "linux"
     #elif SUN
