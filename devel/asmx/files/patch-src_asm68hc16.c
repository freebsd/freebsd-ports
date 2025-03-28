--- src/asm68hc16.c.orig	2025-03-25 02:17:39 UTC
+++ src/asm68hc16.c
@@ -345,7 +345,7 @@ static int M68HC16_DoCPUOpcode(int typ, int parm)
     char    *oldLine;
     int     token;
 //  char    force;
-    char    reg;
+    signed char    reg;
     bool    known;
 
     switch (typ) {
