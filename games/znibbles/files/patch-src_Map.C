--- src/Map.C.orig	1999-05-10 03:39:48 UTC
+++ src/Map.C
@@ -32,7 +32,7 @@
 #endif 
 
 #include <stdio.h>
-#include <iostream.h>
+#include <iostream>
 #include <string.h>
 
 #include "Map.H"
@@ -61,7 +61,7 @@ void Map::make(int x, int y)
 
   // @@ do something appropriate here
   if (_types == NULL)
-    cerr << "Map::make(): malloc failed. Everything should crash." << endl;
+    std::cerr << "Map::make(): malloc failed. Everything should crash." << std::endl;
 
   clear();
 }
@@ -112,39 +112,39 @@ void Map::draw_point(int x, int y, int c
 // Text based display of this map (debug purposes)
 void Map::display()
 {
-  cout << endl;
+  std::cout << std::endl;
   
   for (int i = 0; i < _y; i++) {
     for (int j = 0; j < _x; j++)
-      cout << _map[i][j] << " ";
-    cout << endl;
+      std::cout << _map[i][j] << " ";
+    std::cout << std::endl;
   }
 }
 
 // Text based display of the types in the map (debug purposes)
 void Map::display_t()
 {
-  cout << endl;
+  std::cout << std::endl;
   
   for (int i = 0; i < _y; i++) {
     for (int j = 0; j < _x; j++) {
-      cout << "? " ;
-      //      cout << _maptype[i][j].length() << " ";
+      std::cout << "? " ;
+      //      std::cout << _maptype[i][j].length() << " ";
     }
-    cout << endl;
+    std::cout << std::endl;
   }
 }
 
 void Map::add_type(int x, int y, _Object& obj) 
 { 
   if (_types_index >= _types_size - 1) {
-//     cout << "Map::add_type(): realloc()" << endl;
+//     std::cout << "Map::add_type(): realloc()" << std::endl;
     // resize type array
     _types_size += 200;    // @@ computation has to be done correctly
     _types = (MapType *) realloc(_types, _types_size * sizeof(MapType)); 
     // @@ Do something in case of error !
     if (_types == NULL)
-      cerr << "Map::add_type: realloc failed. Everything should crash." << endl;    
+      std::cerr << "Map::add_type: realloc failed. Everything should crash." << std::endl;    
   }
 
   _types[_types_index].object = &obj;
@@ -170,15 +170,15 @@ void Map::print_type(int x, int y) 
   MapType * mt = get_type(x, y);
 
   if (mt == NULL) 
-    cout << "<empty>";
+    std::cout << "<empty>";
   else {
-    cout << "<" << mt->object;
+    std::cout << "<" << mt->object;
     mt = mt->next;
     while (mt != NULL) {
-      cout << "," << mt->object;
+      std::cout << "," << mt->object;
       mt = mt->next;
     }
-    cout << ">";
+    std::cout << ">";
   }
   
 }
