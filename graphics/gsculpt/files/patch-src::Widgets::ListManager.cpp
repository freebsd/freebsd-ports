--- ./src/Widgets/ListManager.cpp.orig	Mon Jul 21 19:25:18 2003
+++ ./src/Widgets/ListManager.cpp	Mon Jul 21 19:25:30 2003
@@ -10,7 +10,7 @@
 
 #include "ListManager.h"
 
-
+using std::set;
 
 
 ListManager::ListManager(const string& columnTitle)
