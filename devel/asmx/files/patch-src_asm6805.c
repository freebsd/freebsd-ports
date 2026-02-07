--- src/asm6805.c.orig	2025-03-25 02:16:34 UTC
+++ src/asm6805.c
@@ -180,7 +180,7 @@ static int M6805_DoCPUOpcode(int typ, int parm)
     char    *oldLine;
     int     token;
     char    force;
-    char    reg;
+    signed char    reg;
 
     switch (typ) {
         case o_Inh08:       // 68HCS08 inherent instructions
