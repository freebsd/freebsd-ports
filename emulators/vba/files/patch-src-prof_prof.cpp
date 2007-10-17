--- src/prof/prof.cpp.orig	2007-10-04 01:07:54.000000000 +0200
+++ src/prof/prof.cpp	2007-10-04 01:08:31.000000000 +0200
@@ -279,7 +279,7 @@
 
 void profCount()
 {
-  register char *selfpc;
+  register u32 selfpc;
   register unsigned short *frompcindex;
   register struct tostruct *top;
   register struct tostruct *prevtop;
@@ -292,7 +292,7 @@
   
   /* selfpc = pc pushed by mcount call.
      This identifies the function that was just entered.  */
-  selfpc = (char *) reg[14].I;
+  selfpc = (u32) reg[14].I;
   /* frompcindex = pc in preceding frame.
      This identifies the caller of the function just entered.  */
   frompcindex = (unsigned short *) reg[12].I;
