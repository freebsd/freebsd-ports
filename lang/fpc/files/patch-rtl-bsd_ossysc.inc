--- rtl/bsd/ossysc.inc	2009-05-02 10:40:44.000000000 +0100
+++ rtl/bsd/ossysc.inc	2010-08-12 11:36:07.000000000 +0100
@@ -94,11 +94,11 @@
 
 begin
  {$ifdef CPU64}
-  Fpmmap:=pointer(ptruint(do__syscall(TSysParam(syscall_nr_mmap),TSysParam(Start),TSysParam(Len),TSysParam(Prot),TSysParam(Flags),TSysParam(fd),TSysParam(offst),0,0)));
+  Fpmmap:=pointer(ptruint(do_syscall(TSysParam(syscall_nr_mmap),TSysParam(Start),TSysParam(Len),TSysParam(Prot),TSysParam(Flags),TSysParam(fd),0,TSysParam(offst))));
 {$else}
-  Fpmmap:=pointer(ptruint(do_syscall(syscall_nr_mmap,TSysParam(Start),Len,Prot,Flags,fd,
+  Fpmmap:=pointer(ptruint(do_syscall(syscall_nr_mmap,TSysParam(Start),Len,Prot,Flags,fd,0,
         {$ifdef FPC_BIG_ENDIAN}    hi(offst),lo(offst){$endif}
-        {$ifdef FPC_LITTLE_ENDIAN} lo(offst),hi(offst){$endif},0
+        {$ifdef FPC_LITTLE_ENDIAN} lo(offst),hi(offst){$endif}
         )));
 {$endif}
 end;
