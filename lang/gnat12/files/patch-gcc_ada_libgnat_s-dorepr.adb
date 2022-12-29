--- gcc/ada/libgnat/s-dorepr.adb.orig	2022-08-19 08:09:52 UTC
+++ gcc/ada/libgnat/s-dorepr.adb
@@ -61,8 +61,9 @@ package body Product is
       --  Spill the input into the appropriate (maybe larger) bit container,
       --  mask out the low bits and reload the modified value.
 
-      case Num'Machine_Mantissa is
-         when 24 =>
+      --  Patch by Stephane Carrez to handle the case of FreeBSD
+      case Num'Size is
+         when 32 =>
             declare
                Rep32 : aliased Interfaces.Unsigned_32;
                Temp  : Num := N with Address => Rep32'Address;
@@ -76,7 +77,7 @@ package body Product is
                X := Temp;
             end;
 
-         when 53 =>
+         when 64 =>
             declare
                Rep64 : aliased Interfaces.Unsigned_64;
                Temp  : Num := N with Address => Rep64'Address;
@@ -90,7 +91,7 @@ package body Product is
                X := Temp;
             end;
 
-         when 64 =>
+         when 128 =>
             declare
                Rep80 : aliased array (1 .. 2) of Interfaces.Unsigned_64;
                Temp  : Num := N with Address => Rep80'Address;
