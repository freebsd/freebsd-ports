--- subcommander/subcommander.cpp.orig	2009-09-20 18:10:18.000000000 +0900
+++ subcommander/subcommander.cpp	2012-05-10 06:03:26.000000000 +0900
@@ -64,12 +64,6 @@
 #endif // _WIN32
 }
 
-void exit_neon()
-{
-#ifdef _WIN32
-  ne_sock_exit();
-#endif // _WIN32
-}
 
 
 /** main for running the tests. */
@@ -123,7 +117,7 @@
     // no way to bring up a dialog if something went wrong in the basic
     // initialization.
 
-    fprintf( stderr, e.getError()->getMessage() );
+    fprintf( stderr, "%s", e.getError()->getMessage().getStr() );
     return EXIT_FAILURE;
   }
 
@@ -167,7 +161,6 @@
     //config.save();
 
     exit_ssl();
-    exit_neon();
 
     TargetRepository::teardown();
     stopStackProcess();
