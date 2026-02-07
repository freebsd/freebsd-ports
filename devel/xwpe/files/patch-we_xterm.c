--- we_xterm.c.orig	2008-03-19 17:50:00.000000000 +0100
+++ we_xterm.c	2008-03-19 17:52:02.000000000 +0100
@@ -95,7 +95,7 @@
  e_u_ini_size = e_ini_size;
  e_u_setlastpic = e_setlastpic;
  WpeMouseChangeShape = (void (*)(WpeMouseShape))WpeNullFunction;
- WpeMouseRestoreShape = (void (*)(WpeMouseShape))WpeNullFunction;
+ WpeMouseRestoreShape = WpeNullFunction;
 /* WpeMouseChangeShape = WpeXMouseChangeShape;
  WpeMouseRestoreShape = WpeXMouseRestoreShape;*/
  WpeDisplayEnd = WpeNullFunction;
