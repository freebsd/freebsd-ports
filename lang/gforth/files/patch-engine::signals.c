--- engine/signals.c.orig	Sun Mar  9 16:06:56 2003
+++ engine/signals.c	Tue Mar  9 14:44:48 2004
@@ -142,10 +142,18 @@
 #ifdef FPE_INTOVF
   case FPE_INTOVF: code=-11; break; /* integer overflow */
 #endif
+#ifdef FPE_FLTDIV
   case FPE_FLTDIV: code=-42; break; /* floating point divide by zero */
+#endif
+#ifdef FPE_FLTOVF
   case FPE_FLTOVF: code=-43; break; /* floating point overflow  */
+#endif
+#ifdef FPE_FLTUND
   case FPE_FLTUND: code=-54; break; /* floating point underflow  */
+#endif
+#ifdef FPE_FLTRES
   case FPE_FLTRES: code=-41; break; /* floating point inexact result  */
+#endif
 #if 0 /* defined by Unix95, but unnecessary */
   case FPE_FLTINV: /* invalid floating point operation  */
   case FPE_FLTSUB: /* subscript out of range  */
