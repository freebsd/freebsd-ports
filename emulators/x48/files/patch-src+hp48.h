--- src/hp48.h.orig	Sat Jun 28 20:50:52 2003
+++ src/hp48.h	Sat Jun 28 20:52:14 2003
@@ -246,7 +246,7 @@
 
   word_8	unknown2;
 
-  char		timer1;		/* may NOT be unsigned !!! */
+  signed char	timer1;		/* may NOT be unsigned !!! */
   word_32	timer2;
 
   long		t1_instr;
