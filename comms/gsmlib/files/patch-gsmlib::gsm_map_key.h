--- gsmlib/gsm_map_key.h.orig	Wed May 15 04:38:12 2002
+++ gsmlib/gsm_map_key.h	Wed Aug 18 22:19:20 2004
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
@@ -61,14 +71,6 @@
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
