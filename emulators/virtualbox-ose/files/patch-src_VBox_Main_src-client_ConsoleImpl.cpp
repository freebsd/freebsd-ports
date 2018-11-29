--- src/VBox/Main/src-client/ConsoleImpl.cpp.orig	2018-11-08 19:42:03 UTC
+++ src/VBox/Main/src-client/ConsoleImpl.cpp
@@ -9859,7 +9859,7 @@ void Console::i_powerUpThreadTask(VMPowerUpTask *pTask
 
         alock.acquire();
 
-        /* Enable client connections to the server. */
+        /* Enable client connections to the VRDP server. */
         pConsole->i_consoleVRDPServer()->EnableConnections();
 
 #ifdef VBOX_WITH_AUDIO_VRDE
@@ -9876,9 +9876,6 @@ void Console::i_powerUpThreadTask(VMPowerUpTask *pTask
                 pConsole->mAudioVRDE->doAttachDriverViaEmt(pConsole->mpUVM, &alock);
         }
 #endif
-
-        /* Enable client connections to the VRDP server. */
-        pConsole->i_consoleVRDPServer()->EnableConnections();
 
 #ifdef VBOX_WITH_VIDEOREC
         BOOL fVideoRecEnabled = FALSE;
