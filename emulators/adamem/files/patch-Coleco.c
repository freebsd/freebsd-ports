--- Coleco.c.orig	Wed Sep 22 13:28:07 2004
+++ Coleco.c	Wed Sep 22 13:32:20 2004
@@ -616,7 +616,7 @@
  OutE0,OutE0,OutE0,OutE0,OutE0,OutE0,OutE0,OutE0
 };
 
-void Z80_Out (unsigned Port,byte Val)
+FASTCALL void Z80_Out (unsigned Port,byte Val)
 {
  OutPortFn fn;
  Port&=0xff;
@@ -763,7 +763,7 @@
  InpE0,InpE0,InpE2,InpE2,InpE0,InpE0,InpE2,InpE2
 };
 
-byte Z80_In (unsigned Port)
+FASTCALL byte Z80_In (unsigned Port)
 {
  InPortFn fn;
  Port&=0xff;
