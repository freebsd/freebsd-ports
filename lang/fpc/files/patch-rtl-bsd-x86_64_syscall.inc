--- rtl/bsd/x86_64/syscall.inc	2008-09-13 19:17:13.000000000 +0100
+++ rtl/bsd/x86_64/syscall.inc	2010-08-12 11:35:15.000000000 +0100
@@ -219,7 +219,6 @@
 .LSyscOK:
 end;
 
-
 function fpsysCall(sysnr,param1,param2,param3,param4,param5,param6 : TSysParam):TSysResult; assembler;[public,alias:'FPC_DOSYS6'];
 
 asm
@@ -232,7 +231,6 @@
   movq param6,%r9
   syscall                 { Do the system call. }
   jnb .LSyscOK            { branch to exit if ok, errorhandler otherwise}
-
   movq  %rax,%rdx
 {$ifdef FPC_PIC}
   movq  fpc_threadvar_relocate_proc@GOTPCREL(%rip),%rax
@@ -257,50 +255,11 @@
 .LSyscOK:
 
 end;
-//                    edi   esi   edx 	 ecx    r8      r9   stack
-function fp_sysCall(sysnr,param1,param2,param3,param4,param5,param6 : TSysParam):TSysResult; assembler;[public,alias:'FPC__DOSYS'];
 
-asm
-  movq sysnr,%rax         { Syscall number -> rax.  }
-  movq param1,%rdi        { shift arg1 - arg6. }
-  movq param2,%rsi
-  movq param3,%rdx
-  movq param4,%r10
-  movq param5,%r8
-  movq param6,%r9
-  syscall                 { Do the system call. }
-  jnb .LSyscOK            { branch to exit if ok, errorhandler otherwise}
-  movq  %rax,%rdx
-{$ifdef FPC_PIC}
-  movq  fpc_threadvar_relocate_proc@GOTPCREL(%rip),%rax
-  movq  (%rax),%rax
-  movq  Errno@GOTPCREL(%rip),%r11
-{$else FPC_PIC}
-  movq  fpc_threadvar_relocate_proc,%rax
-  leaq  Errno,%r11
-{$endif FPC_PIC}
-  testq %rax,%rax
-  jne   .LThread
-  movl  %edx,8(%r11)
-  jmp   .LNoThread
-.LThread:
-  pushq %rdx
-  movq  (%r11),%rdi
-  call  *%rax
-  popq  %rdx
-  movl  %edx,(%rax)
-.LNoThread:
-  movq  $-1,%rax
-.LSyscOK:
-  add    $0x18,%rsp
-end;
-
-
-//                    edi   esi   edx 	 ecx    r8      r9   stack  stack
-function fp_sysCall(sysnr,param1,param2,param3,param4,param5,param6,param7 : TSysParam):TSysResult; assembler;[public,alias:'FPC__DOSYS7'];
+function fp_sysCall(sysnr,param1,param2,param3,param4,param5,param6,param7 : TSysParam):TSysResult; assembler;[public,alias:'FPC_DOSYS7'];
 
 asm
-  sub    $0x10,%rsp
+  subq   $0x10,%rsp
   movq   sysnr,%rax       { Syscall number -> rax.  }
   movq   param1,%rdi      { shift arg1 - arg6. }
   movq   param2,%rsi
@@ -309,7 +268,7 @@
   movq   param5,%r8
   movq   param6,%r9
   movq   param7,%r11
-  movq   %r11,(%rsp)
+  movq   %r11,8(%rsp)
   syscall                 { Do the system call. }
   jnb .LSyscOK            { branch to exit if ok, errorhandler otherwise}
   movq  %rax,%rdx
@@ -334,6 +293,6 @@
 .LNoThread:
   movq  $-1,%rax
 .LSyscOK:
-  add    $0x10,%rsp
+  addq   $0x10,%rsp
 end;
 

