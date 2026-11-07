--- hedgewars/LuaPas.pas.orig	2025-07-22 17:12:55 UTC
+++ hedgewars/LuaPas.pas
@@ -27,7 +27,7 @@
 
 type
 {$IFNDEF PAS2C}
-    size_t   = Cardinal;
+    size_t   = PtrUInt;
 {$ENDIF}
     Psize_t  = ^size_t;
     PPointer = ^Pointer;
