--- sql/json_dom.h.orig	2018-03-17 00:21:21.146040000 +0300
+++ sql/json_dom.h	2018-03-17 00:21:26.264131000 +0300
@@ -368,7 +368,7 @@
   Json_object class.
 */
 typedef std::map<std::string, Json_dom *, Json_key_comparator,
-  Malloc_allocator<std::pair<std::string, Json_dom *> > > Json_object_map;
+  Malloc_allocator<std::pair<const std::string, Json_dom *> > > Json_object_map;
 
 /**
   Represents a JSON container value of type "object" (ECMA), type
