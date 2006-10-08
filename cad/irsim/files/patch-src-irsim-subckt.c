--- src/irsim/subckt.c.orig	Sun Oct  8 13:20:09 2006
+++ src/irsim/subckt.c	Sun Oct  8 13:20:30 2006
@@ -24,6 +24,7 @@
 
 extern	userSubCircuit	subs[];
 
+private int HashSub();
 
 private int subs_cmp(a, b)
 SubCircuit *a;
