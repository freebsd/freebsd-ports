--- EMULib/LibUnix.c.orig	2013-12-20 21:09:39.000000000 +0100
+++ EMULib/LibUnix.c	2013-12-20 21:56:52.000000000 +0100
@@ -142,7 +142,7 @@
     else
 #endif
       XPutImage(Dsp,Wnd,DefaultGCOfScreen(Scr),VideoImg->XImg,VideoX,VideoY,(XSize-VideoW)>>1,(YSize-VideoH)>>1,VideoW,VideoH);
-    return;
+    return(1);
   }
 
   /* Scale video buffer into OutImg */
@@ -159,6 +159,7 @@
   else
 #endif
     XPutImage(Dsp,Wnd,DefaultGCOfScreen(Scr),OutImg.XImg,0,0,0,0,XSize,YSize);
+    return(1);
 }
 
 /** GetJoystick() ********************************************/
