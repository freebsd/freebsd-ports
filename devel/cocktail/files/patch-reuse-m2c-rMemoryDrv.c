--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/rMemoryDrv.c	Tue Feb 15 14:26:56 1994
+++ ./reuse/m2c/rMemoryDrv.c	Thu Aug  5 18:49:34 2004
@@ -61,7 +61,7 @@
   notbest = 112;
   large = 128;
   for (;;) {
-    for (i = 7; i <= 24; i += 1) {
+    for (i = 7; i <= 12; i += 1) {
       IO_WriteS((rSystem_tFile)IO_StdOutput, (STRING)"        i = ", 12L);
       IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)i, 10L);
       IO_WriteNl((rSystem_tFile)IO_StdOutput);
