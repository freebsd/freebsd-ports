$FreeBSD$

author:  Jean-Yves Lefort 

--- src/celutil/resmanager.h.orig	Tue Feb 15 18:52:35 2005
+++ src/celutil/resmanager.h	Tue Feb 15 18:57:38 2005
@@ -72,7 +72,7 @@
         {
             ResourceHandle h = handles.size();
             resources.insert(resources.end(), info);
-            handles.insert(ResourceHandleMap::value_type(info, h));
+            handles.insert(typename ResourceHandleMap::value_type(info, h));
             return h;
         }
     }
@@ -105,7 +105,7 @@
                     else
                     {
                         resources[h].state = ResourceLoaded;
-                        loadedResources.insert(NameMap::value_type(resources[h].resolvedName, resources[h].resource));
+                        loadedResources.insert(typename NameMap::value_type(resources[h].resolvedName, resources[h].resource));
                     }
                 }
             }
