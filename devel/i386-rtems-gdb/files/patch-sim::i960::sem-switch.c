--- gdb-5.2/sim/i960/sem-switch.c.orig	Sun Aug 15 13:19:00 2004
+++ gdb-5.2/sim/i960/sem-switch.c	Sun Aug 15 13:21:26 2004
@@ -7337,6 +7337,7 @@
 
     }
   ENDSWITCH (sem) /* End of semantic switch.  */
+  ;
 
   /* At this point `vpc' contains the next insn to execute.  */
 }
