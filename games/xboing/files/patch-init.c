--- init.c.orig	1996-11-22 01:28:46 UTC
+++ init.c
@@ -438,7 +438,7 @@ static void HandleDisplayErrors(displayName)
 		WarningMessage("Your X Window system display variable is not set.");
 	else
 	{
-		sprintf(string, "Cannot connect to display called <%s>.", displayName);
+		snprintf(string, sizeof(string), "Cannot connect to display called <%s>.", displayName);
 		WarningMessage(string);
 	}
 }
@@ -471,10 +471,10 @@ static void PrintUsage()
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
@@ -548,10 +548,11 @@ static void PrintHelp()
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
@@ -599,13 +600,13 @@ static void InitialiseSettings()
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
@@ -687,6 +688,13 @@ static void ParseCommandLine(argv, argc)
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
@@ -750,6 +758,13 @@ static void ParseCommandLine(argv, argc)
 			useDefaultColourmap = True;
 
 			DEBUG("Using default colourmap please.")
+
+		} else if (!compareArgument(argv[i], "-no-usedefcmap", 13))
+		{
+			/* Try to use the default colourmap */
+			useDefaultColourmap = False;
+
+			DEBUG("Not using default colourmap.")
 
 		} else if (!compareArgument(argv[i], "-speed", 5))
 		{
