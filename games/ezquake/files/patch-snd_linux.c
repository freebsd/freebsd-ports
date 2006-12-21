--- snd_linux.c.orig	Tue May 16 06:40:16 2006
+++ snd_linux.c	Tue Dec 19 19:22:24 2006
@@ -21,19 +21,14 @@
 
 #include "quakedef.h"
 
-static qbool SNDDMA_ALSA = true;
 // Note: The functions here keep track of if the sound system is inited.
 // They perform checks so that the real functions are only called if appropriate.
 
 
 // Prototypes
-qbool SNDDMA_Init_ALSA(void);
 qbool SNDDMA_Init_OSS(void);
-int SNDDMA_GetDMAPos_ALSA(void);
 int SNDDMA_GetDMAPos_OSS(void);
-void SNDDMA_Shutdown_ALSA(void);
 void SNDDMA_Shutdown_OSS(void);
-void SNDDMA_Submit_ALSA(void);
 
 
 // Main functions
@@ -41,49 +36,24 @@
 {
 	int retval;
 
-	// Give user the option to force OSS...
-	if (Cvar_VariableValue("s_noalsa")) {
-		// User wants us to use OSS...
-		SNDDMA_ALSA = false;
-		Com_Printf("sound: Using OSS at user's request...\n");
-		retval = SNDDMA_Init_OSS();
-	} else {
-		// Try ALSA first...
-		Com_Printf("sound: Attempting to initialise ALSA...\n");
-		retval = SNDDMA_Init_ALSA();
-		if (retval) {
-			SNDDMA_ALSA = true;
-		} else {
-			// Fall back to OSS...
-			SNDDMA_ALSA = false;
-			Com_Printf("sound: Falling back to OSS...\n");
-			retval = SNDDMA_Init_OSS();
-		}
-	}
+	Com_Printf("sound: Initializing OSS...\n");
+	retval = SNDDMA_Init_OSS();
 
 	return retval;
 }
 
 int SNDDMA_GetDMAPos(void)
 {
-	if (SNDDMA_ALSA)
-		return SNDDMA_GetDMAPos_ALSA();
-	else
-		return SNDDMA_GetDMAPos_OSS();
+	return SNDDMA_GetDMAPos_OSS();
 }
 
 void SNDDMA_Shutdown(void)
 {
-	if (SNDDMA_ALSA)
-		SNDDMA_Shutdown_ALSA();
-	else
-		SNDDMA_Shutdown_OSS();
+	SNDDMA_Shutdown_OSS();
 }
 
 //Send sound to device if buffer isn't really the dma buffer
 void SNDDMA_Submit(void)
 {
-	if (SNDDMA_ALSA)
-		SNDDMA_Submit_ALSA();
-		// OSS doesn't use this so no need to call it.
+	// OSS doesn't use this so no need to call it.
 }
