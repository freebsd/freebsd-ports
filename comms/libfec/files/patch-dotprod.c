--- dotprod.c.orig	2006-10-13 01:10:53 UTC
+++ dotprod.c
@@ -54,16 +54,21 @@ void freedp(void *p){
   switch(Cpu_mode){
   case PORT:
   default:
+    return;
+  break;
 #ifdef __i386__
   case MMX:
   case SSE:
     return freedp_mmx(p);
+  break;
   case SSE2:
     return freedp_sse2(p);
+  break;
 #endif
 #ifdef __VEC__
   case ALTIVEC:
     return freedp_av(p);
+  break;
 #endif
   }
 }
