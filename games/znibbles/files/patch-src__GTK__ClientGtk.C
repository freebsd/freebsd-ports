--- src/GTK/ClientGtk.C	Sat Apr 24 02:47:47 1999
+++ src/GTK/ClientGtk.C	Sat Oct 26 00:38:02 2002
@@ -51,7 +51,7 @@
 
   world.run();                 // start the client
 
-  cout << "Yeah !\n" << endl;
+  std::cout << "Yeah !\n" << std::endl;
   return 0;
 }
 
