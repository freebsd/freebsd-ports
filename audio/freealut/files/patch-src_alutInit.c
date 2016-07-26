--- src/alutInit.c.orig	2006-05-08 09:28:07 UTC
+++ src/alutInit.c
@@ -147,11 +147,7 @@ alutExit (void)
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
