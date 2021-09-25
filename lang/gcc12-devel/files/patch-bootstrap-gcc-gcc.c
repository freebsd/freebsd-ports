commit abdf63d782cba82b5ecf264248518cbb065650ed
Author: Iain Sandoe <iain@sandoe.co.uk>
Date:   Mon Sep 20 07:41:49 2021 +0100

    Driver: Fix bootstrap with DEFAULT_{ASSEMBLER,LINKER,DSYMUTIL}.
    
    The patch at r12-3662-g5fee8a0a9223d factored the code for
    printing the names of programes into a separate function.
    However the moved editions that print out the names of the
    assembler, linker (and dsymutil on Darwin) when those are
    specified at configure-time were not adjusted accordingly,
    leading to a bootstrap fail.
    
    Fixed by testing specifically for execute OK, since we know
    these are programs.
    
    Signed-off-by: Iain Sandoe <iain@sandoe.co.uk>
    
    gcc/ChangeLog:
    
            * gcc.c: Test for execute OK when we find the
            programs for assembler linker and dsymutil and those
            were specified at configure-time.

--- gcc/gcc.c
+++ gcc/gcc.c
@@ -3083,17 +3083,17 @@ find_a_program (const char *name)
   /* Do not search if default matches query. */
 
 #ifdef DEFAULT_ASSEMBLER
-  if (! strcmp (name, "as") && access (DEFAULT_ASSEMBLER, mode) == 0)
+  if (! strcmp (name, "as") && access (DEFAULT_ASSEMBLER, X_OK) == 0)
     return xstrdup (DEFAULT_ASSEMBLER);
 #endif
 
 #ifdef DEFAULT_LINKER
-  if (! strcmp (name, "ld") && access (DEFAULT_LINKER, mode) == 0)
+  if (! strcmp (name, "ld") && access (DEFAULT_LINKER, X_OK) == 0)
     return xstrdup (DEFAULT_LINKER);
 #endif
 
 #ifdef DEFAULT_DSYMUTIL
-  if (! strcmp (name, "dsymutil") && access (DEFAULT_DSYMUTIL, mode) == 0)
+  if (! strcmp (name, "dsymutil") && access (DEFAULT_DSYMUTIL, X_OK) == 0)
     return xstrdup (DEFAULT_DSYMUTIL);
 #endif
 
