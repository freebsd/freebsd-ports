--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/SetsDrv.c	Tue Feb 15 14:27:00 1994
+++ ./reuse/m2c/SetsDrv.c	Thu Aug  5 18:49:34 2004
@@ -25,39 +25,116 @@
   for (i = 2; i <= max; i += 1) {
     Sets_Include(&t, i);
   }
+  Sets_WriteSet((rSystem_tFile)IO_StdOutput, t);
+  IO_WriteNl((rSystem_tFile)IO_StdOutput);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Size(&t), 5L);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Card(&t), 5L);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Minimum(&t), 5L);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Maximum(&t), 5L);
+  IO_WriteNl((rSystem_tFile)IO_StdOutput);
   Sets_AssignEmpty(&s);
   Sets_AssignElmt(&s, 1L);
   Sets_Assign(&u, t);
   Sets_Union(&s, t);
+  Sets_WriteSet((rSystem_tFile)IO_StdOutput, t);
+  IO_WriteNl((rSystem_tFile)IO_StdOutput);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Size(&t), 5L);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Card(&t), 5L);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Minimum(&t), 5L);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Maximum(&t), 5L);
+  IO_WriteNl((rSystem_tFile)IO_StdOutput);
   Sets_AssignEmpty(&t);
   for (i = 0; i <= max; i += 2) {
     Sets_Include(&t, i);
   }
+  Sets_WriteSet((rSystem_tFile)IO_StdOutput, t);
+  IO_WriteNl((rSystem_tFile)IO_StdOutput);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Size(&t), 5L);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Card(&t), 5L);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Minimum(&t), 5L);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Maximum(&t), 5L);
+  IO_WriteNl((rSystem_tFile)IO_StdOutput);
   Sets_Difference(&s, t);
   for (i = 0; i <= max; i += 3) {
     Sets_Exclude(&s, i);
   }
+  Sets_WriteSet((rSystem_tFile)IO_StdOutput, s);
+  IO_WriteNl((rSystem_tFile)IO_StdOutput);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Size(&s), 5L);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Card(&s), 5L);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Minimum(&s), 5L);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Maximum(&s), 5L);
+  IO_WriteNl((rSystem_tFile)IO_StdOutput);
   for (i = 0; i <= max; i += 5) {
     Sets_Exclude(&s, i);
   }
+  Sets_WriteSet((rSystem_tFile)IO_StdOutput, s);
+  IO_WriteNl((rSystem_tFile)IO_StdOutput);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Size(&s), 5L);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Card(&s), 5L);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Minimum(&s), 5L);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Maximum(&s), 5L);
+  IO_WriteNl((rSystem_tFile)IO_StdOutput);
   for (i = 0; i <= max; i += 7) {
     Sets_Exclude(&s, i);
   }
+  Sets_WriteSet((rSystem_tFile)IO_StdOutput, s);
+  IO_WriteNl((rSystem_tFile)IO_StdOutput);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Size(&s), 5L);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Card(&s), 5L);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Minimum(&s), 5L);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Maximum(&s), 5L);
+  IO_WriteNl((rSystem_tFile)IO_StdOutput);
   for (i = 0; i <= max; i += 11) {
     Sets_Exclude(&s, i);
   }
+  Sets_WriteSet((rSystem_tFile)IO_StdOutput, s);
+  IO_WriteNl((rSystem_tFile)IO_StdOutput);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Size(&s), 5L);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Card(&s), 5L);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Minimum(&s), 5L);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Maximum(&s), 5L);
+  IO_WriteNl((rSystem_tFile)IO_StdOutput);
   for (i = 0; i <= max; i += 13) {
     Sets_Exclude(&s, i);
   }
+  Sets_WriteSet((rSystem_tFile)IO_StdOutput, s);
+  IO_WriteNl((rSystem_tFile)IO_StdOutput);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Size(&s), 5L);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Card(&s), 5L);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Minimum(&s), 5L);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Maximum(&s), 5L);
+  IO_WriteNl((rSystem_tFile)IO_StdOutput);
   for (i = 0; i <= max; i += 17) {
     Sets_Exclude(&s, i);
   }
+  Sets_WriteSet((rSystem_tFile)IO_StdOutput, s);
+  IO_WriteNl((rSystem_tFile)IO_StdOutput);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Size(&s), 5L);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Card(&s), 5L);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Minimum(&s), 5L);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Maximum(&s), 5L);
+  IO_WriteNl((rSystem_tFile)IO_StdOutput);
   for (i = 0; i <= max; i += 19) {
     Sets_Exclude(&s, i);
   }
+  Sets_WriteSet((rSystem_tFile)IO_StdOutput, s);
+  IO_WriteNl((rSystem_tFile)IO_StdOutput);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Size(&s), 5L);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Card(&s), 5L);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Minimum(&s), 5L);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Maximum(&s), 5L);
+  IO_WriteNl((rSystem_tFile)IO_StdOutput);
   for (i = 0; i <= max; i += 23) {
     Sets_Exclude(&s, i);
   }
+  Sets_WriteSet((rSystem_tFile)IO_StdOutput, s);
+  IO_WriteNl((rSystem_tFile)IO_StdOutput);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Size(&s), 5L);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Card(&s), 5L);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Minimum(&s), 5L);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Maximum(&s), 5L);
+  IO_WriteNl((rSystem_tFile)IO_StdOutput);
   for (i = 0; i <= max; i += 29) {
     Sets_Exclude(&s, i);
   }
@@ -101,7 +178,7 @@
   Sets_Include(&s, 3L);
   Sets_Include(&s, 7L);
   IO_WriteNl((rSystem_tFile)IO_StdOutput);
-  IO_WriteS((rSystem_tFile)IO_StdOutput, (STRING)"enter Size and Set like below! (Size=0 terminates)", 50L);
+  IO_WriteS((rSystem_tFile)IO_StdOutput, (STRING)"enter MaxSet and Set like below! (Size=0 terminates)", 52L);
   IO_WriteNl((rSystem_tFile)IO_StdOutput);
   IO_WriteS((rSystem_tFile)IO_StdOutput, (STRING)"10 ", 3L);
   Sets_WriteSet((rSystem_tFile)IO_StdOutput, s);
@@ -115,6 +192,10 @@
       goto EXIT_1;
     }
     Sets_MakeSet(&s, i);
+    Sets_WriteSet((rSystem_tFile)IO_StdOutput, s);
+    IO_WriteS((rSystem_tFile)IO_StdOutput, (STRING)" Card = ", 8L);
+    IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Card(&s), 0L);
+    IO_WriteNl((rSystem_tFile)IO_StdOutput);
     Sets_ReadSet((rSystem_tFile)IO_StdInput, &s);
     Sets_WriteSet((rSystem_tFile)IO_StdOutput, s);
     IO_WriteS((rSystem_tFile)IO_StdOutput, (STRING)" Card = ", 8L);
