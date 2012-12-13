--- subcommander/commands/ScCmd.cpp.orig	2008-11-23 01:46:19.000000000 +0900
+++ subcommander/commands/ScCmd.cpp	2012-05-10 05:55:05.000000000 +0900
@@ -28,13 +28,13 @@
   _client = client;
   _prgscb = progress;
 
-  apr_time_t t1 = apr_time_now();
+  //apr_time_t t1 = apr_time_now();
 
   //_prgscb->started( getId(), /*_param*/, getCancel() );
   run();
   //_prgscb->finished( getId(), /*_param*/, time );
 
-  apr_time_t t2 = apr_time_now();
+  //apr_time_t t2 = apr_time_now();
 
   //_prgscb->time( _id, ((double)(t2-t1)/1000.0) );
 }
