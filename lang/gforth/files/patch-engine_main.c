--- engine/main.c.orig	Sun Aug 24 12:06:29 2003
+++ engine/main.c	Sat Oct 21 11:36:19 2006
@@ -70,8 +70,18 @@
 
 void engine_callback(Xt* fcall, void * alist)
 {
+  Cell *rp = RP;
+  Cell *sp = SP;
+  Float *fp = FP;
+  Address lp = LP;
+
   clist = (va_alist)alist;
-  engine(fcall, SP, RP, FP, LP);
+  engine(fcall, sp, rp, fp, lp);
+
+  RP = rp;
+  SP = sp;
+  FP = fp;
+  LP = lp;
 }
 #endif
 
