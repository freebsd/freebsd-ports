--- rtl/bsd/bunxsysc.inc	2015-08-04 04:31:09.000000000 -0500
+++ rtl/bsd/bunxsysc.inc	2020-02-21 18:30:23.409088000 -0500
@@ -379,10 +379,10 @@
 {$if defined(freebsd) or defined (dragonfly)}
   {$define PIPE_RESULT_IN_EAX_AND_EDX}
 {$endif}
-Function FPpipe(var fildes : tfildes):cint;
+Function FPpipe(var fildes : tfildes; flags:cint):cint;
 {$ifndef PIPE_RESULT_IN_EAX_AND_EDX}
 begin
-  fppipe:=do_syscall(syscall_nr_pipe,TSysParam(@fildes));
+  fppipe:=do_syscall(syscall_nr_pipe2,TSysParam(@fildes), TSysParam(flags));
 end;
 {$else}
 var
