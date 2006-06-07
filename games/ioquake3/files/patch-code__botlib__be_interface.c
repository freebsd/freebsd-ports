--- ./code/botlib/be_interface.c.orig	Wed Apr 26 10:36:58 2006
+++ ./code/botlib/be_interface.c	Wed Jun  7 19:34:25 2006
@@ -155,7 +155,7 @@
 	} else {
 		Com_sprintf(logfilename, sizeof(logfilename), "botlib.log");
 	}
-	Log_Open(logfilename);
+	Log_Open("/dev/null");
 	//
 	botimport.Print(PRT_MESSAGE, "------- BotLib Initialization -------\n");
 	//
