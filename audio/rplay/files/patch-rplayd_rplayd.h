--- rplayd/rplayd.h.orig	1999-03-10 07:58:04 UTC
+++ rplayd/rplayd.h
@@ -73,7 +73,6 @@ extern RPLAY_AUDIO_TABLE *rplay_audio_ta
 extern fd_set read_mask;
 extern fd_set write_mask;
 extern int debug;
-extern int inetd;
 extern int rptp_timeout;
 extern char hostname[];
 extern char *hostaddr;
