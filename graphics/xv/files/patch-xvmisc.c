--- xvmisc.c.orig	2010-02-11 14:29:41.000000000 +0100
+++ xvmisc.c	2010-02-11 15:25:03.000000000 +0100
@@ -504,6 +504,7 @@
 }
 
 
+extern int InSignal;
 /***********************************/
 void Quit(i)
      int i;
@@ -601,7 +619,8 @@
     }
   }
 
+  if (InSignal == 0)
   XSync(theDisp, False);
   exit(i);
 }
 
