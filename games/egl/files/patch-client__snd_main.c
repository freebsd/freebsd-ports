--- ./client/snd_main.c.orig	Tue May 23 20:05:59 2006
+++ ./client/snd_main.c	Tue May 23 20:06:00 2006
@@ -25,7 +25,8 @@
 #include "snd_local.h"
 
 qBool					snd_isActive = qTrue;
-qBool					snd_isInitialized;
+qBool					snd_isFirstInit = qTrue;
+qBool					snd_isInitialized = qFalse;
 qBool					snd_isDMA;
 qBool					snd_isAL;
 
@@ -870,7 +871,7 @@
 	int		initTime;
 
 	if (snd_isInitialized)
-		Snd_Shutdown ();
+		return;
 
 	Com_Printf (0, "\n--------- Sound Initialization ---------\n");
 
@@ -892,27 +893,44 @@
 	s_testsound			= Cvar_Register ("s_testsound",			"0",			0);
 	s_primary			= Cvar_Register ("s_primary",			"0",			CVAR_ARCHIVE|CVAR_LATCH_AUDIO);	// win32 specific
 
-	al_allowExtensions	= Cvar_Register ("al_allowExtensions",	"1",			CVAR_ARCHIVE|CVAR_LATCH_AUDIO);
-	al_device			= Cvar_Register ("al_device",			"",				CVAR_ARCHIVE);
-	al_dopplerFactor	= Cvar_Register ("al_dopplerFactor",	"1",			CVAR_ARCHIVE);
-	al_dopplerVelocity	= Cvar_Register ("al_dopplerVelocity",	"16384",		CVAR_ARCHIVE);
-	al_driver			= Cvar_Register ("al_driver",			AL_DRIVERNAME,	CVAR_ARCHIVE|CVAR_LATCH_AUDIO);
-	al_errorCheck		= Cvar_Register ("al_errorCheck",		"1",			CVAR_ARCHIVE);
-	al_ext_eax2			= Cvar_Register ("al_ext_eax2",			"1",			CVAR_ARCHIVE|CVAR_LATCH_AUDIO);
-	al_gain				= Cvar_Register ("al_gain",				"5",			CVAR_ARCHIVE);
-	al_minDistance		= Cvar_Register ("al_minDistance",		"100",			CVAR_ARCHIVE);
-	al_maxDistance		= Cvar_Register ("al_maxDistance",		"8192",			CVAR_ARCHIVE);
-	al_rollOffFactor	= Cvar_Register ("al_rollOffFactor",	"0.8",			CVAR_ARCHIVE);
+	if (s_initSound->integer == 2) {
+		al_allowExtensions	= Cvar_Register ("al_allowExtensions",	"1",			CVAR_ARCHIVE|CVAR_LATCH_AUDIO);
+		al_device			= Cvar_Register ("al_device",			"",				CVAR_ARCHIVE);
+		al_dopplerFactor	= Cvar_Register ("al_dopplerFactor",	"1",			CVAR_ARCHIVE);
+		al_dopplerVelocity	= Cvar_Register ("al_dopplerVelocity",	"16384",		CVAR_ARCHIVE);
+		al_driver			= Cvar_Register ("al_driver",			AL_DRIVERNAME,	CVAR_ARCHIVE|CVAR_LATCH_AUDIO);
+		al_errorCheck		= Cvar_Register ("al_errorCheck",		"1",			CVAR_ARCHIVE);
+		al_ext_eax2			= Cvar_Register ("al_ext_eax2",			"1",			CVAR_ARCHIVE|CVAR_LATCH_AUDIO);
+		al_gain				= Cvar_Register ("al_gain",				"5",			CVAR_ARCHIVE);
+		al_minDistance		= Cvar_Register ("al_minDistance",		"100",			CVAR_ARCHIVE);
+		al_maxDistance		= Cvar_Register ("al_maxDistance",		"8192",			CVAR_ARCHIVE);
+		al_rollOffFactor	= Cvar_Register ("al_rollOffFactor",	"0.8",			CVAR_ARCHIVE);
+	}
+
+	/*
+	 * We need to keep the snd_restart command even if the sound subsystem
+	 * is not started, because there has to be a way to start it.
+	 */
+	if (snd_isFirstInit) {
+		cmd_snd_restart = Cmd_AddCommand ("snd_restart",	Snd_Restart_f,		"Restarts the audio subsystem");
+		snd_isFirstInit = qFalse;
+	}
 
-	cmd_snd_restart = Cmd_AddCommand ("snd_restart",	Snd_Restart_f,		"Restarts the audio subsystem");
 	cmd_play		= Cmd_AddCommand ("play",			Snd_Play_f,			"Plays a sound");
 	cmd_stopSound	= Cmd_AddCommand ("stopsound",		Snd_StopAllSounds,	"Stops all currently playing sounds");
 	cmd_soundList	= Cmd_AddCommand ("soundlist",		Snd_SoundList_f,	"Prints out a list of loaded sound files");
 	cmd_soundInfo	= Cmd_AddCommand ("soundinfo",		Snd_SoundInfo_f,	"Prints out information on sound subsystem");
 
+	/*
+	 * Make Snd_Shutdown() abort the startup if necessary (it quits when
+	 * the subsystem is not initialized, so make it think the opposite).
+	 */
+	snd_isInitialized = qTrue;
+
 	if (!s_initSound->value) {
 		Com_Printf (0, "...not initializing\n");
 		Com_Printf (0, "----------------------------------------\n");
+		Snd_Shutdown();
 		return;
 	}
 
@@ -927,13 +945,13 @@
 		}
 	}
 	if (!snd_isAL) {
-		if (!DMASnd_Init())
+		if (!DMASnd_Init()) {
+			Snd_Shutdown();
 			return;
+		}
 		snd_isDMA = qTrue;
 	}
 
-	snd_isInitialized = qTrue;
-
 	Snd_StopAllSounds ();
 
 	Com_Printf (0, "----------------------------------------\n");
@@ -955,18 +973,19 @@
 {
 	int		size;
 
-	Cmd_RemoveCommand ("snd_restart", cmd_snd_restart);
+	if (!snd_isInitialized)
+		return;
+
 	Cmd_RemoveCommand ("play", cmd_play);
 	Cmd_RemoveCommand ("stopsound", cmd_stopSound);
 	Cmd_RemoveCommand ("soundlist", cmd_soundList);
 	Cmd_RemoveCommand ("soundinfo", cmd_soundInfo);
 
-	if (!snd_isInitialized)
-		return;
-	snd_isInitialized = qFalse;
-
 	Com_Printf (0, "\n------------ Sound Shutdown ------------\n");
 
+	// Stop all sounds
+	Snd_StopAllSounds();
+
 	// Free all sounds
 	Snd_FreeSounds ();
 
@@ -984,6 +1003,8 @@
 		ALSnd_Shutdown ();
 		snd_isAL = qFalse;
 	}
+
+	snd_isInitialized = qFalse;
 
 	Com_Printf (0, "----------------------------------------\n");
 }
