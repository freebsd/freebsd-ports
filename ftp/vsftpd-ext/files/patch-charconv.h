--- charconv.h.orig	2012-03-27 21:15:01 UTC
+++ charconv.h
@@ -134,7 +134,8 @@ struct codepage_map
 {
   unsigned int char_code; // The first element is count bytes of char.
   unsigned int order;
-} _codepage_map;
+};
+extern struct codepage_map _codepage_map;
 
 typedef struct codepage_map * map_ptr;
 
