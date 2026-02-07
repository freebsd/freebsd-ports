--- src/st-flash/flash_opts.c.orig	2025-04-02 12:36:36 UTC
+++ src/st-flash/flash_opts.c
@@ -17,7 +17,7 @@
 #include <helper.h>
 
 static bool starts_with(const char * str, const char * prefix) {
-    uint32_t n = strlen(prefix);
+    size_t n = strlen(prefix);
 
     if (strlen(str) < n) { return (false); }
 
@@ -70,7 +70,7 @@ static int32_t get_integer_from_char_array (const char
         fprintf (stderr, "*** Error: Integer greater than UINT32_MAX, cannot convert to int32_t\n");
         return (-1);
     } else {
-        *read_value = value;
+        *read_value = (uint32_t)value;
         return (0);
     }
 }
@@ -199,7 +199,7 @@ int32_t flash_get_opts(struct flash_opts* o, int32_t a
             if (result != 0) {
                 return (bad_arg ("--flash"));
             } else {
-                o->flash_size = (size_t)flash_size;
+                o->flash_size = flash_size;
             }
         } else if (strcmp(av[0], "--connect-under-reset") == 0) {
             o->connect = CONNECT_UNDER_RESET;
@@ -259,7 +259,7 @@ int32_t flash_get_opts(struct flash_opts* o, int32_t a
             if (result != 0) {
                 return bad_arg ("size");
             } else {
-                o->size = (size_t) size;
+                o->size =  size;
             }
         }
 
@@ -283,7 +283,7 @@ int32_t flash_get_opts(struct flash_opts* o, int32_t a
             if (result != 0) {
                 return bad_arg ("size");
             } else {
-                o->size = (size_t) size;
+                o->size = size;
             }
 
             break;
@@ -300,7 +300,7 @@ int32_t flash_get_opts(struct flash_opts* o, int32_t a
                 if (result != 0) {
                     return bad_arg("option bytes read: invalid size");
                 } else {
-                    o->size = (size_t) size;
+                    o->size = size;
                 }
             }
             break;
