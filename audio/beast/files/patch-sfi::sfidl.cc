--- sfi/sfidl.cc.orig	Wed Jun 23 17:13:58 2004
+++ sfi/sfidl.cc	Wed Jun 23 17:14:18 2004
@@ -45,7 +45,7 @@
       return 0;
     }
 
-  if((argc-optind) != 1)
+  if (argc != 2)
     {
       options.printUsage ();
       return 1;
