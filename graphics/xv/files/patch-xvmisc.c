--- src/xvmisc.c.orig	2023-07-17 01:25:42 UTC
+++ src/xvmisc.c
@@ -504,6 +504,7 @@ void FatalError (identifier)
 }
 
 
+extern int InSignal;
 /***********************************/
 void Quit(i)
      int i;
@@ -597,6 +598,7 @@ void Quit(i)
     }
   }
 
+  if (InSignal == 0)
   XSync(theDisp, False);
   exit(i);
 }
