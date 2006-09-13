--- PACC/Util/SignalHandler.cpp.orig	Wed Oct  5 06:38:27 2005
+++ PACC/Util/SignalHandler.cpp	Mon Sep 11 16:09:17 2006
@@ -89,7 +89,7 @@
 	//the signal is not defined under Windows, do nothing
 	if(inSignalNumber < 1) return;
 	if(smOldSigIgn[inSignalNumber] != NULL) return;
-	smOldSigIgn[inSignalNumber] = (void*)signal(inSignalNumber, SIG_IGN);
+	smOldSigIgn[inSignalNumber] = (void*)signal(inSignalNumber, (void (*)(int))SIG_IGN);
 }
 
 /*!
@@ -126,7 +126,7 @@
 		signal(inSignalNumber, (__sighandler_t)smOldSigIgn[inSignalNumber]);
 #endif
 	}
-	else signal(inSignalNumber, SIG_DFL);
+	else signal(inSignalNumber, (void (*)(int))SIG_DFL);
 	smOldSigIgn[inSignalNumber] = NULL;
 }
 
