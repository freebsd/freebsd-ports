--- src/Settings.cpp.orig	2020-12-12 00:59:10 UTC
+++ src/Settings.cpp
@@ -1054,7 +1054,7 @@ void Settings_ModalOptions (struct thread_Settings *mE
 	    bail = true;
 	} else if (isTxStartTime(mExtSettings) || isTxHoldback(mExtSettings)) {
 	    Timestamp now;
-	    long nowsecs = now.getSecs();
+	    time_t nowsecs = now.getSecs();
 	    // fill out the formats in the event they are needed per an time error
 	    char start_timebuf[80];
 	    struct tm ts = *localtime(&mExtSettings->txstart_epoch.tv_sec);
