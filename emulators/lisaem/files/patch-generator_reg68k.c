--- generator/reg68k.c.orig	2007-12-04 16:57:08 UTC
+++ generator/reg68k.c
@@ -1308,7 +1308,7 @@ else                                    
 
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
-                if (abort_opcode==1) {EXIT(476,0,"MMU/BUS/Address exception occured on opcode fetch!\n");}
+                if (abort_opcode==1) {EXITR(476,0,"MMU/BUS/Address exception occured on opcode fetch!\n");}
                 abort_opcode=0;          // clear any addr/bus errors/traps/etc that may have occured.
 
                 InstructionRegister=ipc->opcode;
@@ -1397,7 +1397,7 @@ else                                    
                                 InstructionRegister=ipc->opcode;
                                 abort_opcode=0;
                                 if (ipc->function) ipc->function(ipc);
-                                else {   EXIT(277,0,"No ipc function at %d/%08x, even after attempting to get one!\n",context,pc24);}
+                                else {   EXITR(277,0,"No ipc function at %d/%08x, even after attempting to get one!\n",context,pc24);}
                              }
                     }  // if we have it, execute, else loop is done. :)
 
