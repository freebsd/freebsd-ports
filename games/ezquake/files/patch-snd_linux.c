--- ./snd_linux.c.orig	Fri Sep  9 08:00:27 2005
+++ ./snd_linux.c	Tue Aug 29 20:59:12 2006
@@ -6,7 +6,6 @@
 
 #include "quakedef.h" 
 
-qbool SNDDMA_ALSA;
 int snd_inited;
 // Note: The functions here keep track of if the sound system is inited.
 //       They perform checks so that the real functions are only called if
@@ -15,13 +14,9 @@
 
 // Prototypes
 
-qbool SNDDMA_Init_ALSA(void);
 qbool SNDDMA_Init_OSS(void);
-int SNDDMA_GetDMAPos_ALSA(void);
 int SNDDMA_GetDMAPos_OSS(void);
-void SNDDMA_Shutdown_ALSA(void);
 void SNDDMA_Shutdown_OSS(void);
-void SNDDMA_Submit_ALSA(void);
 void SNDDMA_Submit_OSS(void);
 
 
@@ -31,30 +26,8 @@
 {
     int retval;
 
-    // Give user the option to force OSS...
-    if(COM_CheckParm("-noalsa")) // || Cvar_VariableValue("s_noalsa") )
-    {
-        // User wants us to use OSS...
-        Com_Printf("sound: Using OSS at user's request...\n");
-        retval = SNDDMA_Init_OSS();
-    }
-    else
-    {
-        // Try ALSA first...
-        Com_Printf("sound: Attempting to initialise ALSA...\n");
-        retval = SNDDMA_Init_ALSA();
-        if( retval )
-        {
-            SNDDMA_ALSA = true;
-        }
-        else
-        {
-            // Fall back to OSS...
-            SNDDMA_ALSA = false;
-            Com_Printf("sound: Falling back to OSS...\n");
-            retval = SNDDMA_Init_OSS();
-        }
-    }
+    Com_Printf("sound: Initializing OSS...\n");
+    retval = SNDDMA_Init_OSS();
 
     snd_inited = retval;
     return retval;
@@ -64,10 +37,7 @@
 {
     if( snd_inited )
     {
-        if( SNDDMA_ALSA )
-	    return SNDDMA_GetDMAPos_ALSA();
-        else
-	    return SNDDMA_GetDMAPos_OSS();
+	return SNDDMA_GetDMAPos_OSS();
     }
     else
         return 0;
@@ -77,10 +47,7 @@
 {
     if (snd_inited)
     {
-        if( SNDDMA_ALSA )
-            SNDDMA_Shutdown_ALSA();
-        else
-            SNDDMA_Shutdown_OSS();
+        SNDDMA_Shutdown_OSS();
 
         snd_inited = 0;
     }
@@ -97,8 +64,6 @@
 {
     if( snd_inited )
     {
-        if( SNDDMA_ALSA )
-            SNDDMA_Submit_ALSA();
         // OSS doesn't use this so no need to call it.
     }
 }
