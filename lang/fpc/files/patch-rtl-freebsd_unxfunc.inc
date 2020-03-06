--- rtl/freebsd/unxfunc.inc	2020-02-21 18:39:27.076200000 -0500
+++ rtl/freebsd/unxfunc.inc	2020-02-21 18:39:47.649039000 -0500
@@ -49,8 +49,9 @@
 }
 var
   pip  : tfildes;
+  flags : cint;
 begin
-  assignPipe:=fppipe(pip);
+  assignPipe:=fppipe(pip, flags);
   pipe_in:=pip[0];
   pipe_out:=pip[1];
 end;
