--- rtl/bsd/ossysc.inc	2020-10-03 18:58:28.503033000 -0500
+++ rtl/bsd/ossysc.inc	2020-10-03 19:01:01.207504000 -0500
@@ -76,9 +76,9 @@
 
 begin
   {$ifdef CPU64}
-    Fplseek:=do_syscall(syscall_nr___syscall,syscall_nr_lseek,TSysParam(fd),0,Offset,whence);
+    Fplseek:=do_syscall(syscall_nr___syscall,syscall_nr_lseek,TSysParam(fd),Offset,whence);
   {$else}
-    Fplseek:=do_syscall(syscall_nr___syscall,syscall_nr_lseek,0,TSysParam(fd),0,
+    Fplseek:=do_syscall(syscall_nr___syscall,syscall_nr_lseek,0,TSysParam(fd),
        {$ifdef ENDIAN_BIG}hi(offset),lo(offset){$endif}
        {$ifdef ENDIAN_LITTLE}lo(Offset),hi(offset){$endif},
        Whence);
@@ -90,9 +90,9 @@
 
 begin
  {$ifdef CPU64}
-   Fpftruncate:=Do_syscall(syscall_nr___syscall,syscall_nr_ftruncate, fd  ,0   ,flength);
+   Fpftruncate:=Do_syscall(syscall_nr___syscall,syscall_nr_ftruncate, fd  ,flength);
  {$else}
-   Fpftruncate:=Do_syscall(syscall_nr___syscall,syscall_nr_ftruncate,0,fd,0,lo(flength),hi(flength));
+   Fpftruncate:=Do_syscall(syscall_nr___syscall,syscall_nr_ftruncate,0,fd,lo(flength),hi(flength));
  {$endif}
 
 end;
@@ -102,9 +102,9 @@
 
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
