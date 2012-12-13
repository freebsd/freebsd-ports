--- subcommander/commands/IgnoreCmd.cpp.orig	2008-12-30 23:58:59.000000000 +0900
+++ subcommander/commands/IgnoreCmd.cpp	2012-05-10 05:53:54.000000000 +0900
@@ -30,7 +30,7 @@
 
 void IgnoreCmd::run()
 {
-  sc::Error* err;
+  sc::Error* err (0);
 
   _prgscb->started( _param, getCancel() );
 
