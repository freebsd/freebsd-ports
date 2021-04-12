--- test/kfg/kfgtest.cpp.orig	2019-08-20 18:27:10 UTC
+++ test/kfg/kfgtest.cpp
@@ -280,6 +280,8 @@ FIXTURE_TEST_CASE(predef_OS, KfgFixture)
     CreateAndLoad(GetName(), "var=$(OS)\n");
     #if LINUX
         #define OS "linux"
+    #elif BSD
+        #define OS "bsd"    
     #elif SUN
         #define OS "sun"
     #elif MAC
