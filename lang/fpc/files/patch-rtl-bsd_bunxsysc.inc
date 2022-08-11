--- rtl/bsd/bunxsysc.inc	2015-07-14 16:58:27.000000000 -0500
+++ rtl/bsd/bunxsysc.inc	2022-05-27 11:25:13.139710000 -0500
@@ -374,40 +374,12 @@
  FPutime:=do_syscall(syscall_nr_utimes,TSysParam(path),TSysParam(tvp));
 end;
 
-function __pipe_call(sysnr:TSysParam):TSysResult; {$ifdef cpui386}oldfpccall{$endif} external name 'FPC_DOSYS0';
+function FPpipe(var fildes : tfildes; flags:cint):cint;
 
-{$if defined(freebsd) or defined (dragonfly)}
-  {$define PIPE_RESULT_IN_EAX_AND_EDX}
-{$endif}
-Function FPpipe(var fildes : tfildes):cint;
-{$ifndef PIPE_RESULT_IN_EAX_AND_EDX}
 begin
-  fppipe:=do_syscall(syscall_nr_pipe,TSysParam(@fildes));
+  fppipe:=do_syscall(syscall_nr_pipe2,TSysParam(@fildes), TSysParam(flags));
 end;
-{$else}
-var
-  a, b: cInt;
-begin
-  asm
-  {$ifdef CPUi386}
-    pushl syscall_nr_pipe
-    call __pipe_call
-    movl %eax, a
-    movl %edx, b
-  {$else}
-    movq syscall_nr_pipe, %rdi
-    call __pipe_call
-    movl %eax, a
-    movl %edx, b
-  {$endif}
-  end;
 
-  fpPipe := a; // eax is in a, no matter if it worked or not
-  fildes[0] := a;
-  fildes[1] := b;
-end;
-{$endif}
-
 function FPfcntl(fildes:cint;Cmd:cint;Arg:cint):cint;
 
 begin
@@ -497,9 +469,15 @@
 {
   Get all information on a link (the link itself), and return it in info.
 }
-
+const
+  AT_FDCWD=-100;
+  AT_SYMLINK_NOFOLLOW=$0200;
 begin
+{$ifdef freebsd}
+ fpLStat:=do_syscall(syscall_nr_fstatat,AT_FDCWD,TSysParam(path),TSysParam(Info),AT_SYMLINK_NOFOLLOW);
+{$else}
  fpLStat:=do_syscall(syscall_nr_lstat,TSysParam(path),TSysParam(info));
+{$endif}
 end;
 
 function fpNice(N:cint):cint;
