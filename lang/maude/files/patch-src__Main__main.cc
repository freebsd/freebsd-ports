--- ./src/Main/main.cc.orig	2010-03-19 22:29:26.000000000 +0100
+++ ./src/Main/main.cc	2011-11-10 19:33:07.000000000 +0100
@@ -269,6 +269,11 @@
       directory = executableDirectory;
       return true;
     }
+  if (directoryManager.checkAccess(MAUDE_DATADIR, fileName, R_OK))
+    {
+      directory = MAUDE_DATADIR;
+      return true;
+    }
   if (directoryManager.checkAccess(".", fileName, R_OK))
     {
       directory = ".";
