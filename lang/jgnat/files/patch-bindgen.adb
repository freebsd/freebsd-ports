--- bindgen.adb.orig	Fri Sep  1 10:13:49 2000
+++ bindgen.adb	Fri Feb  8 21:58:21 2002
@@ -1890,10 +1890,10 @@
 
       --  Constants to help defining periods
 
-      Always : constant := 0;
+      --  Always : constant := 0;
       Hour   : constant := 60;
       Day    : constant := 24 * Hour;
-      Month  : constant := 30 * Day;
+      --  Month  : constant := 30 * Day;
 
       Never  : constant := Integer'Last;
       --  Special value indicating no warnings should be given
