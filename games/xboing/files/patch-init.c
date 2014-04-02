--- init.c.orig	1996-11-22 02:28:46.000000000 +0100
+++ init.c	2014-03-30 18:05:40.000000000 +0200
@@ -438,7 +438,7 @@
 		WarningMessage("Your X Window system display variable is not set.");
 	else
 	{
-		sprintf(string, "Cannot connect to display called <%s>.", displayName);
+		snprintf(string, sizeof(string), "Cannot connect to display called <%s>.", displayName);
 		WarningMessage(string);
 	}
 }
@@ -471,10 +471,10 @@
 		"Usage: XBoing [-version] [-usage] [-help] [-sync] ",
 		"[-display <displayName>]\n"); 
     fprintf(stdout, "%s%s\n%s%s\n%s\n",
-		"              [-speed <1-9>] [-scores] [-keys] [-sound] [-setup]",
+		"              [-speed <1-9>] [-scores] [-keys] [-no-sound] [-setup]",
 		" [-nosfx]",
 		"              [-grab] [-maxvol <1-100>] [-startlevel <1-MAX>]",
-		" [-usedefcmap]",
+		" [-no-usedefcmap]",
 		"              [-nickname <name>] [-noicon]");
 
 	/* Exit now */
@@ -548,10 +548,11 @@
         "    -scores                 - Print out the current highscores.\n",
         "    -keys                   - Use keys instead of mouse control.\n",
         "    -sound                  - Turn audio ON for game.\n",
+        "    -no-sound               - Turn audio OFF for game.\n",
         "    -setup                  - Print setup information.\n",
         "    -nosfx                  - Do not use some special effects.\n",
         "    -grab                   - Turn ON pointer grab.\n",
-        "    -usedefcmap             - Use the default colourmap.\n",
+        "    -no-usedefcmap          - Don't use the default colourmap.\n",
 		"    -nickname <name>        - Use nickname instead of real name.\n",
         "    -noicon                 - Do not create a custom icon.\n",
         "    -display <display>      - Set the display for the game.\n");
@@ -599,13 +600,13 @@
 	syncOn = False;
 	debug = False;
 	grabPointer = False;
-	useDefaultColourmap = False;
+	useDefaultColourmap = True;
 
 	/* This will force the use of the users real name */
 	SetNickName("");
 
-	/* The audio is off by default */
-	noSound = True;
+	/* The audio is on by default */
+	noSound = False;
 	noicon 	= False;
 
 	/* So the audio code will use system default */
@@ -687,6 +688,13 @@
 			/* Print out the version information and quit */
 			PrintVersion();
 
+		} else if (!compareArgument(argv[i], "-no-sound", 8))
+		{
+			/* Enable the sound in the game */
+			noSound = True;
+
+			DEBUG("Sound turned off.")
+
 		} else if (!compareArgument(argv[i], "-sound", 5))
 		{
 			/* Enable the sound in the game */
@@ -751,6 +759,13 @@
 
 			DEBUG("Using default colourmap please.")
 
+		} else if (!compareArgument(argv[i], "-no-usedefcmap", 13))
+		{
+			/* Try to use the default colourmap */
+			useDefaultColourmap = False;
+
+			DEBUG("Not using default colourmap.")
+
 		} else if (!compareArgument(argv[i], "-speed", 5))
 		{
 			/* Set the speed for the game */
