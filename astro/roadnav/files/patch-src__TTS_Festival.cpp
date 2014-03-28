--- ./src/TTS_Festival.cpp.orig	2007-10-09 04:02:14.000000000 +0200
+++ ./src/TTS_Festival.cpp	2014-03-24 12:28:17.000000000 +0100
@@ -88,7 +88,7 @@
 			ppszArgs[2], 
 			64 + strText.Length(),
 			wxT("echo \\(SayText \\\"%ss\\\"\\) | festival"), 
-			strText.mb_str(*wxConvCurrent)
+			static_cast<const char *>strText.mb_str(*wxConvCurrent)
 			);
 
 	wxExecute(ppszArgs, wxEXEC_SYNC);
