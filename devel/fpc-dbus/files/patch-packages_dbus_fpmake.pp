--- packages/dbus/fpmake.pp.orig	2015-01-05 19:27:06 UTC
+++ packages/dbus/fpmake.pp
@@ -24,7 +24,7 @@ begin
     P.Email := '';
     P.Description := 'D-Bus message bus interface. (1.2.16)';
     P.NeedLibC:= true;
-    P.OSes := [linux];
+    P.OSes := [linux,dragonfly,freebsd];
 
     P.SourcePath.Add('src');
     P.IncludePath.Add('src');
