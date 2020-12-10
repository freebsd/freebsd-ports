--- hedgewars/uWorld.pas.orig	2019-10-07 12:29:22 UTC
+++ hedgewars/uWorld.pas
@@ -1126,11 +1126,13 @@ end;
 
 var preShiftWorldDx: LongInt;
 
-procedure ShiftWorld(Dir: LongInt); inline;
+procedure ShiftWorld(Dir: LongInt);
+var
+    tmp: LongInt;
 begin
     preShiftWorldDx:= WorldDx;
-    WorldDx:= WorldDx + LongInt(Dir * LongInt(playWidth));
-
+    tmp := LongInt(Dir * LongInt(playWidth));
+    WorldDx := WorldDx + tmp;
 end;
 
 procedure UnshiftWorld(); inline;
