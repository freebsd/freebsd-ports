--- packages/a52/fpmake.pp.orig	2015-11-13 21:15:29 UTC
+++ packages/a52/fpmake.pp
@@ -20,7 +20,7 @@ begin
     P.Email := '';
     P.Description := 'A free library for decoding ATSC A/52 streams.';
     P.NeedLibC:= true;
-    P.OSes := [linux,win32];
+    P.OSes := [linux,win32,dragonfly,freebsd];
 
 {$ifdef ALLPACKAGES}
     P.Directory:=ADirectory;
