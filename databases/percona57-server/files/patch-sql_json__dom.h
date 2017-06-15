--- sql/json_dom.h.orig	2017-01-05 16:09:35 UTC
+++ sql/json_dom.h
@@ -337,7 +337,7 @@ struct Json_key_comparator
   Json_object class.
 */
 typedef std::map<std::string, Json_dom *, Json_key_comparator,
-  Malloc_allocator<std::pair<std::string, Json_dom *> > > Json_object_map;
+  Malloc_allocator<std::pair<const std::string, Json_dom *> > > Json_object_map;
 
 /**
   Represents a JSON container value of type "object" (ECMA), type
