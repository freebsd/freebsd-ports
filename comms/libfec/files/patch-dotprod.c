--- dotprod.c.orig	2006-10-13 03:10:53.000000000 +0200
+++ dotprod.c	2014-01-17 12:35:33.000000000 +0100
@@ -54,12 +54,16 @@
   switch(Cpu_mode){
   case PORT:
   default:
+    freedp_port(p);
+    break;
 #ifdef __i386__
   case MMX:
   case SSE:
-    return freedp_mmx(p);
+    freedp_mmx(p);
+    break;
   case SSE2:
-    return freedp_sse2(p);
+    freedp_sse2(p);
+    break;
 #endif
 #ifdef __VEC__
   case ALTIVEC:
