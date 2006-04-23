--- src/alutInit.c.orig	Wed Mar  8 16:40:26 2006
+++ src/alutInit.c	Wed Mar  8 16:41:23 2006
@@ -147,11 +147,7 @@
       return AL_FALSE;
     }
 
-  if (!alcCloseDevice (device))
-    {
-      _alutSetError (ALUT_ERROR_CLOSE_DEVICE);
-      return AL_FALSE;
-    }
+  alcCloseDevice (device);
 
   initialisationState = Unintialized;
   return AL_TRUE;
