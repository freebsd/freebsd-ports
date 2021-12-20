We don't currently have osascript in ports, but for the case when
we actually do, make sure it's not suddenly called and prefer zenity.

--- gameheaders/stratagus-tinyfiledialogs.h.orig	2021-07-17 05:26:07 UTC
+++ gameheaders/stratagus-tinyfiledialogs.h
@@ -2350,6 +2350,7 @@ static int gdialogPresent ( )
 
 static int osascriptPresent ( )
 {
+	return 0;
 	static int lOsascriptPresent = -1 ;
 	if ( lOsascriptPresent < 0 )
 	{
