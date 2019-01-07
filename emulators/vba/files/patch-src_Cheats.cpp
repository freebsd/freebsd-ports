--- src/Cheats.cpp.orig	2018-12-29 21:27:02 UTC
+++ src/Cheats.cpp
@@ -1344,12 +1344,12 @@ void cheatsAddCBACode(const char *code, const char *de
   sscanf(buffer, "%x", &value);
 
   u8 array[8] = {
-    address & 255,
-    (address >> 8) & 255,
-    (address >> 16) & 255,
-    (address >> 24) & 255,
-    (value & 255),
-    (value >> 8) & 255,
+    static_cast<u8>(address & 255),
+    static_cast<u8>((address >> 8) & 255),
+    static_cast<u8>((address >> 16) & 255),
+    static_cast<u8>((address >> 24) & 255),
+    static_cast<u8>((value & 255)),
+    static_cast<u8>((value >> 8) & 255),
     0,
     0
   };
