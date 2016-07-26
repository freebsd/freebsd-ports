--- markerlist.h.orig	1999-07-13 18:14:07 UTC
+++ markerlist.h
@@ -56,21 +56,23 @@ private:
 class MarkerList
 {
 public:
-  MarkerList() { list.setAutoDelete(TRUE); }
- ~MarkerList() { list.clear(); }
-  inline void append(const Location *l) { list.append(l); }
-  inline Location *first() { return list.first(); }
-  inline Location *last() { return list.last(); }
-  inline Location *next() { return list.next(); }
-  inline Location *prev() { return list.prev(); }
-  inline Location *current() { return list.current(); }
+  MarkerList() { }
+ ~MarkerList() { qDeleteAll(list); list.clear(); }
+  inline void append(Location *l) { list.append(l); }
+//  inline Location *first() { return list.first(); }
+//  inline Location *last() { return list.last(); }
+//  inline Location *next() { return list.next(); }
+//  inline Location *prev() { return list.prev(); }
+//  inline Location *current() { return list.current(); }
+  inline Location *atindex(int i) {return list[i]; }	// Q&D
   inline uint count() { return list.count(); }
-  inline void clear() { list.clear(); }
+  inline void clear() { qDeleteAll(list); list.clear(); }
+  inline int size() { return list.size(); }
   
   bool loadMarkerFile(const char *filename);
   
 protected:
-  QList<Location> list;
+  QList<Location *> list;
 };
 
 #endif
