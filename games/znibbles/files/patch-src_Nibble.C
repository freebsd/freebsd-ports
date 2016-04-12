--- src/Nibble.C.orig	1998-11-17 08:36:32 UTC
+++ src/Nibble.C
@@ -58,7 +58,7 @@ void Nibble:: add_description(Trame &t)
 void Nibble:: read_description(Trame &t)
 {
   if (t.get_char() != NEW_NIBBLE) {
-    cerr << "Nibble::read_description(): ohhh le bordel!\n";
+    std::cerr << "Nibble::read_description(): ohhh le bordel!\n";
     exit(1);
   }
   
@@ -81,10 +81,10 @@ void Nibble::read_description0(Trame &t)
 
 void Nibble::display()
 {
-  cout << "   ID:"<< id;
+  std::cout << "   ID:"<< id;
   printf(" %04x", classtype);
-  cout << " Nibble  " << pos.x << "x" << pos.y << " value=" << value 
-       << " type=" << type << endl;
+  std::cout << " Nibble  " << pos.x << "x" << pos.y << " value=" << value 
+       << " type=" << type << std::endl;
 }
 
 
