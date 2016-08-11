--- src/Base.H.orig	1999-05-12 01:40:22 UTC
+++ src/Base.H
@@ -32,7 +32,7 @@
 #define __H_BASE__
 
 
-#include <iostream.h>
+#include <iostream>
 
 
 // #define DEBUG
@@ -55,8 +55,8 @@ public:
   inline ~Base()
   {
     total--;
-    cout << "  <" << id << "/" << global_id 
-	 << " deleted><left=" << total << ">  " << endl;
+    std::cout << "  <" << id << "/" << global_id 
+	 << " deleted><left=" << total << ">  " << std::endl;
   }
 #else
 
@@ -65,7 +65,7 @@ public:
 
 #endif
 
-  void display() {  cout << "ID: " << id << endl; }
+  void display() {  std::cout << "ID: " << id << std::endl; }
 
 private:
   static int global_id;
