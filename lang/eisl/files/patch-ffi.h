--- ffi.h.orig	2024-04-30 07:10:18 UTC
+++ ffi.h
@@ -4,7 +4,7 @@
 
 #ifndef FFI_H
 #define FFI_H
-#define CELLSIZE 20000000
+#define CELLSIZE 10000000
 // TCC does not have support for "static conts" as compile time constant
 #ifdef __TINYC__
 #define NIL 0
