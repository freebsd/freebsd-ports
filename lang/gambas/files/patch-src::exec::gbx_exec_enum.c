--- ./src/exec/gbx_exec_enum.c.orig	Fri Apr  9 21:33:05 2004
+++ ./src/exec/gbx_exec_enum.c	Fri Apr  9 21:33:33 2004
@@ -41,8 +41,8 @@
   local = &BP[code & 0xFF];
 
   EXEC_object(local, &class, &object, &defined);
-  EXEC_enum_data = (void *)(local[1]._void.value);
-  memset(EXEC_enum_data, 0, 8);
+  EXEC_enum_data = (void *)(&local[1]._void.ptype);
+  memset(EXEC_enum_data, 0, 12);
 
   EXEC_special(SPEC_FIRST, class, object, 0, TRUE);
 }
@@ -58,7 +58,7 @@
   local = &BP[PC[-1] & 0xFF];
 
   EXEC_object(local, &class, &object, &defined);
-  EXEC_enum_data = (void *)(local[1]._void.value);
+  EXEC_enum_data = (void *)(&local[1]._void.ptype);
 
   EXEC_enum_stop = FALSE;
 
