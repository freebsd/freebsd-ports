--- ./src/ObjEdit/ObjectCollection.h.orig	Mon Jul 21 18:43:57 2003
+++ ./src/ObjEdit/ObjectCollection.h	Mon Jul 21 18:47:09 2003
@@ -23,7 +23,10 @@
 #include "Journal.h"
 #include "ListManager.h"
 
-
+using std::string;
+using std::map;
+using std::set;
+using std::list;
 
 
 class ObjectCollection : public JournalCollection
