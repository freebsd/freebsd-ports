--- libs/m3core/src/unix/freebsd-4.sparc64/Unix.i3	Sat Mar 23 04:28:45 2002
+++ libs/m3core/src/unix/freebsd-4.sparc64/Unix.i3	Mon Apr 17 13:04:12 2006
@@ -128,7 +128,7 @@
   F_GETFL =  3;   (* Get fd status flags *)
   F_SETFL =  4;   (* Set fd status flags *)
 
-  (* in these three cases, you need to pass LOOPHOLE (ADR (v), int) 
+  (* in these three cases, you need to pass LOOPHOLE (ADR (v), long) 
      for arg, where v is a variable of type struct_flock *)
   F_GETOWN = 5;   (* Set owner *)
   F_SETOWN = 6;   (* Get owner *)
@@ -155,7 +155,7 @@
   F_WRLCK = 3; (* Write lock *)
   F_UNLCK = 2; (* Remove lock(s) *)
 
-<*EXTERNAL*> PROCEDURE fcntl (fd, request, arg: int): int;
+<*EXTERNAL*> PROCEDURE fcntl (fd, request: int; arg: long): int;
 (* ok *)
 
 (*** flock - apply or remove an advisory lock on an open file ***)
