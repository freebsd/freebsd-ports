--- src/GTK/ClientGtk.C.orig	1999-04-23 16:47:47 UTC
+++ src/GTK/ClientGtk.C
@@ -51,7 +51,7 @@ int main(int argc, char **argv)
 
   world.run();                 // start the client
 
-  cout << "Yeah !\n" << endl;
+  std::cout << "Yeah !\n" << std::endl;
   return 0;
 }
 
