--- hedgewars/uScript.pas.orig	2025-07-22 17:12:55 UTC
+++ hedgewars/uScript.pas
@@ -436,7 +436,7 @@
 
 function lc_parsecommand(L : Plua_State) : LongInt; Cdecl;
 var t: PChar;
-    i,c: LongWord;
+    i,c: size_t;
     s: shortstring;
 begin
     if CheckLuaParamCount(L, 1, 'ParseCommand', 'string') then
