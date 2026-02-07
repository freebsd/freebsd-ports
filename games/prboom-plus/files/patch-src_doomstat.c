--- src/doomstat.c.orig	2010-12-16 21:37:35 UTC
+++ src/doomstat.c
@@ -57,7 +57,7 @@ GameExe_t game_exe;
 
 // e6y
 // it's required for demos recorded in "demo compatibility" mode by boom201 for example
-int demover;
+extern int demover;
 
 int comp[COMP_TOTAL], default_comp[COMP_TOTAL];    // killough 10/98
 
