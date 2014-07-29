--- src/LongObject.C	Mon May 10 08:59:45 1999
+++ src/LongObject.C	Sat Oct 26 00:39:11 2002
@@ -128,7 +128,7 @@
 void LongObject::read_description(Trame &t)
 {
   if (t.get_char() != NEW_LONGOBJ) {
-    cerr << "LongObject::read_description(): ohhh le bordel!\n";
+    std::cerr << "LongObject::read_description(): ohhh le bordel!\n";
     exit(1);
   }
 
@@ -161,17 +161,17 @@
 
 void LongObject::display()
 {
-  cout << "   ID:"<< id;
+  std::cout << "   ID:"<< id;
   printf(" %04x", classtype);
-  cout << " LongObj " << pos.x << "x" \
+  std::cout << " LongObj " << pos.x << "x" \
        << pos.y << " len=" << length << " q=[ " ;
 
   Pix pix = queue.first();
   for (int i = length - 1; i > 0; i--) {
-    cout << queue(pix) << " ";
+    std::cout << queue(pix) << " ";
     queue.next(pix);
   }
-  cout << "]" <<  endl;
+  std::cout << "]" <<  std::endl;
 }
 
 
