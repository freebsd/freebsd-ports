--- src/Base.H	Wed May 12 11:40:22 1999
+++ src/Base.H	Sat Oct 26 00:30:09 2002
@@ -32,7 +32,7 @@
 #define __H_BASE__
 
 
-#include <iostream.h>
+#include <iostream>
 
 
 // #define DEBUG
@@ -55,8 +55,8 @@
   inline ~Base()
   {
     total--;
-    cout << "  <" << id << "/" << global_id 
-	 << " deleted><left=" << total << ">  " << endl;
+    std::cout << "  <" << id << "/" << global_id 
+	 << " deleted><left=" << total << ">  " << std::endl;
   }
 #else
 
@@ -65,7 +65,7 @@
 
 #endif
 
-  void display() {  cout << "ID: " << id << endl; }
+  void display() {  std::cout << "ID: " << id << std::endl; }
 
 private:
   static int global_id;
