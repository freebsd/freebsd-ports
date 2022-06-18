--- rtl/bsd/ossysc	2019-11-05 11:17:53.000000000 -0500
+++ rtl/bsd/ossysc.inc	2022-05-28 16:58:54.884379000 -0500
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
@@ -138,10 +138,20 @@
   Fprename:=do_syscall(syscall_nr_rename,TSysParam(old),TSysParam(newpath));
 end;
 
-function Fpstat(const path: pchar; var buf : stat):cint; [public, alias : 'FPC_SYSC_STAT'];
+Function fpFstatat(fd: cint; path: pchar; var sb: stat; flag: cint):cint;
+begin
+ fpFStatat:=do_syscall(syscall_nr_fstatat,fd,TSysParam(path),TSysParam(@sb),flag);
+end;
 
+function Fpstat(const path: pchar; var buf : stat):cint; [public, alias : 'FPC_SYSC_STAT'];
+const
+ AT_FDCWD=-100;
 begin
+{$ifdef freebsd}
+ Fpstat:=FpFstatat(AT_FDCWD, path, buf, 0);
+{$else}
  Fpstat:=do_syscall(syscall_nr_stat,TSysParam(path),TSysParam(@buf));
+{$endif}
 end;
 
 
@@ -171,6 +181,12 @@
 
 const DIRBLKSIZ=1024;
 
+{$ifdef freebsd}
+function FpGetdirentries(fd : cint; buf : pchar; nbytes : clong) : cint;
+begin
+  FpGetdirentries:=do_syscall(syscall_nr_getdirentries,fd,TSysParam(buf), nbytes);
+end;
+{$endif}
 
 function Fpfstat(fd : cint; var sb : stat): cint; forward;
 
@@ -247,7 +263,11 @@
 
 var retval :longint;
 begin
+{$ifdef freebsd}
+ Retval:=FpGetdirentries(dirp^.dd_fd, @dirp^.dd_buf^, DIRBLKSIZ {sizeof(getdentsbuffer)});
+{$else}
  Retval:=do_syscall(syscall_nr_getdents,TSysParam(dirp^.dd_fd),TSysParam(@dirp^.dd_buf^),DIRBLKSIZ {sizeof(getdentsbuffer)});
+{$endif}
    dirp^.dd_rewind:=TSysParam(dirp^.dd_buf);
    if retval=0 then
     begin
