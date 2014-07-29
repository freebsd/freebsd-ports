--- src/Nibble.C	Tue Nov 17 19:36:32 1998
+++ src/Nibble.C	Sat Oct 26 00:40:26 2002
@@ -58,7 +58,7 @@
 void Nibble:: read_description(Trame &t)
 {
   if (t.get_char() != NEW_NIBBLE) {
-    cerr << "Nibble::read_description(): ohhh le bordel!\n";
+    std::cerr << "Nibble::read_description(): ohhh le bordel!\n";
     exit(1);
   }
   
@@ -81,10 +81,10 @@
 
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
 
 
