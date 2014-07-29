--- gsmlib/gsm_map_key.h.orig	Tue May 14 23:38:12 2002
+++ gsmlib/gsm_map_key.h	Sun Sep 24 00:37:00 2006
@@ -25,6 +25,16 @@
 
   // wrapper for map key, can access Sortedtore to get sortOrder()
 
+  template <class SortedStore> class MapKey;
+  
+  // compare two keys
+  template <class SortedStore>
+    extern bool operator<(const MapKey<SortedStore> &x,
+                          const MapKey<SortedStore> &y);
+  template <class SortedStore>
+    extern bool operator==(const MapKey<SortedStore> &x,
+                           const MapKey<SortedStore> &y);
+  
   template <class SortedStore> class MapKey
   {
     SortedStore &_myStore;   // my store
@@ -61,18 +71,10 @@
                        const MapKey<SortedStore> &y);
   };
 
-  // compare two keys
-  template <class SortedStore>
-    extern bool operator<(const MapKey<SortedStore> &x,
-                          const MapKey<SortedStore> &y);
-  template <class SortedStore>
-    extern bool operator==(const MapKey<SortedStore> &x,
-                           const MapKey<SortedStore> &y);
-  
   // MapKey members
   
   template <class SortedStore>
-    bool gsmlib::operator<(const MapKey<SortedStore> &x,
+    bool operator<(const MapKey<SortedStore> &x,
                            const MapKey<SortedStore> &y)
     {
       assert(&x._myStore == &y._myStore);
@@ -97,7 +99,7 @@
     }
 
   template <class SortedStore>
-    bool gsmlib::operator==(const MapKey<SortedStore> &x,
+    bool operator==(const MapKey<SortedStore> &x,
                             const MapKey<SortedStore> &y)
     {
       assert(&x._myStore == &y._myStore);
