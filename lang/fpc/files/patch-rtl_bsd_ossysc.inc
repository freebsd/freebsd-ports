--- rtl/bsd/ossysc.inc	2014-11-23 16:59:25.000000000 -0500
+++ rtl/bsd/ossysc.inc	2020-02-21 21:01:06.087663000 -0500
@@ -72,9 +72,9 @@
 
 begin
   {$ifdef CPU64}
-    Fplseek:=do_syscall(syscall_nr___syscall,syscall_nr_lseek,TSysParam(fd),0,Offset,whence);
+    Fplseek:=do_syscall(syscall_nr___syscall,syscall_nr_lseek,TSysParam(fd),Offset,whence);
   {$else}
-    Fplseek:=do_syscall(syscall_nr___syscall,syscall_nr_lseek,0,TSysParam(fd),0,lo(Offset),{0} hi(offset),Whence);
+    Fplseek:=do_syscall(syscall_nr___syscall,syscall_nr_lseek,0,TSysParam(fd),lo(Offset),{0} hi(offset),Whence);
   {$endif}
 end;
 
@@ -82,11 +82,10 @@
 
 begin
  {$ifdef CPU64}
-   Fpftruncate:=Do_syscall(syscall_nr___syscall,syscall_nr_ftruncate, fd  ,0   ,flength);
+   Fpftruncate:=Do_syscall(syscall_nr___syscall,syscall_nr_ftruncate, fd ,flength);
  {$else}
-   Fpftruncate:=Do_syscall(syscall_nr___syscall,syscall_nr_ftruncate,0,fd,0,lo(flength),hi(flength));
+   Fpftruncate:=Do_syscall(syscall_nr___syscall,syscall_nr_ftruncate,0,fd,lo(flength),hi(flength));
  {$endif}
-
 end;
 
 
@@ -94,9 +93,9 @@
 
 begin
  {$ifdef CPU64}
-  Fpmmap:=pointer(ptruint(do_syscall(TSysParam(syscall_nr_mmap),TSysParam(Start),TSysParam(Len),TSysParam(Prot),TSysParam(Flags),TSysParam(fd),0,TSysParam(offst))));
+  Fpmmap:=pointer(ptruint(do_syscall(TSysParam(syscall_nr_mmap),TSysParam(Start),TSysParam(Len),TSysParam(Prot),TSysParam(Flags),TSysParam(fd),TSysParam(offst))));
 {$else}
- Fpmmap:=pointer(ptruint(do_syscall(syscall_nr_mmap,TSysParam(Start),Len,Prot,Flags,fd,0,
+ Fpmmap:=pointer(ptruint(do_syscall(syscall_nr_mmap,TSysParam(Start),Len,Prot,Flags,fd,
          {$ifdef FPC_BIG_ENDIAN}    hi(offst),lo(offst){$endif}
          {$ifdef FPC_LITTLE_ENDIAN} lo(offst),hi(offst){$endif}
          )));
@@ -282,7 +281,11 @@
  repeat
   novalid:=false;
   CurEntry:=pdirent(dirp^.dd_rewind);
+{$ifdef dragonfly}
+  RecLen:=(CurEntry^.d_namlen + 24) and $FFFFFFF8;
+{$else}
   RecLen:=CurEntry^.d_reclen;
+{$endif}
   if RecLen<>0 Then
    begin {valid direntry?}
     if CurEntry^.d_fileno<>0 then
