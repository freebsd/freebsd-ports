
$FreeBSD$

--- top_setup.c.orig	Tue Jan 12 19:59:40 1993
+++ top_setup.c	Mon Aug 25 00:38:35 2003
@@ -26,18 +26,8 @@
 # include "logo.xbm"
 
 XtAppContext	appc;
-char		*file;
-char		*device;
-Boolean		debug		= False;
-Boolean		display_timer	= True;
-float		volbase		= 187.0;
-float		volpcent	= .267;
-int		replayThreshold	= 4;
-int		pauseSkipInterval	= 15;
-int		scanSkipInterval	= 1;
-float		scanPauseInterval	= .062;
-float		pausePauseInterval	= .500;
-char		*cdInfoDir = NULL;
+
+AppData app_data;
 
 extern char	*getenv();
 
@@ -55,36 +45,36 @@
 };
 
 static XtResource	resources[] = {
-	{ "file", "File", XtRString, sizeof(String), (Cardinal) &file,
+	{ "file", "File", XtRString, sizeof(String), XtOffsetOf(AppData,file),
 		  XtRString, (caddr_t) NULL },
-	{ "device", "Device", XtRString, sizeof(String), (Cardinal) &device,
+	{ "device", "Device", XtRString, sizeof(String), XtOffsetOf(AppData,device),
 		  XtRString, (caddr_t) NULL },
-	{ "debug", "Debug", XtRBoolean, sizeof(Boolean), (Cardinal) &debug,
-		  XtRBoolean, (caddr_t) &debug },
+	{ "debug", "Debug", XtRBoolean, sizeof(Boolean), XtOffsetOf(AppData,debug),
+		  XtRBoolean, &app_data.debug },
 	{ "displayTimer", "DisplayTimer", XtRBoolean, sizeof(Boolean),
-		  (Cardinal) &display_timer, XtRBoolean,
-		  (caddr_t) &display_timer },
+		  XtOffsetOf(AppData,display_timer), XtRBoolean,
+		  &app_data.display_timer },
 	{ "volBase", "VolBase", XtRFloat, sizeof(float),
-		  (Cardinal) &volbase, XtRFloat, (caddr_t) &volbase },
+		  XtOffsetOf(AppData,volbase), XtRFloat, &app_data.volbase },
 	{ "volPcent", "VolPcent", XtRFloat, sizeof(float),
-		  (Cardinal) &volpcent, XtRFloat, (caddr_t) &volpcent },
+		  XtOffsetOf(AppData,volpcent), XtRFloat, &app_data.volpcent },
 	{ "replayThreshold", "replayThreshold", XtRInt, sizeof(int),
-		  (Cardinal) &replayThreshold, XtRInt, 
-		  (caddr_t) &replayThreshold },
+		  XtOffsetOf(AppData,replayThreshold), XtRInt, 
+		  &app_data.replayThreshold },
 	{ "scanSkipInterval", "scanSkipInterval", XtRInt, sizeof(int),
-		  (Cardinal) &scanSkipInterval, XtRInt, 
-		  (caddr_t) &scanSkipInterval },
+		  XtOffsetOf(AppData,scanSkipInterval), XtRInt, 
+		  &app_data.scanSkipInterval },
 	{ "scanPauseInterval", "scanPauseInterval", XtRFloat, sizeof(float),
-		  (Cardinal) &scanPauseInterval, XtRFloat, 
-		  (caddr_t) &scanPauseInterval },
+		  XtOffsetOf(AppData,scanPauseInterval), XtRFloat, 
+		  &app_data.scanPauseInterval },
 	{ "pauseSkipInterval", "pauseSkipInterval", XtRInt, sizeof(int),
-		  (Cardinal) &pauseSkipInterval, XtRInt, 
-		  (caddr_t) &pauseSkipInterval },
+		  XtOffsetOf(AppData,pauseSkipInterval), XtRInt, 
+		  &app_data.pauseSkipInterval },
 	{ "pausePauseInterval", "pausePauseInterval", XtRFloat, sizeof(float),
-		  (Cardinal) &pausePauseInterval, XtRFloat, 
-		  (caddr_t) &pausePauseInterval },
+		  XtOffsetOf(AppData,pausePauseInterval), XtRFloat, 
+		  &app_data.scanPauseInterval },
 	{ "cdInfoDir", "cdInfoDir", XtRString, sizeof(String), 
-		  (Cardinal) &cdInfoDir, XtRString, (caddr_t) NULL },
+		  XtOffsetOf(AppData,cdInfoDir), XtRString, (caddr_t) NULL },
 };
 
 Widget
@@ -98,6 +88,20 @@
 	Arg		arg;
 	char		*s;
 
+	/*
+	 * set default values
+	 */
+
+	app_data.debug = False;
+	app_data.display_timer = True;
+	app_data.volbase = 187.0;
+	app_data.volpcent = 0.267;
+	app_data.replayThreshold = 4;
+	app_data.pauseSkipInterval = 15;
+	app_data.scanSkipInterval = 1;
+	app_data.scanPauseInterval = 0.062;
+	app_data.pausePauseInterval = 0.500;
+
 	XtToolkitInitialize();
 
 	appc = XtCreateApplicationContext();
@@ -123,12 +127,12 @@
 	XtSetValues(top_shell, &arg, 1);
 	
 
-	(void) XtGetApplicationResources(top_shell, (caddr_t) NULL,
+	(void) XtGetApplicationResources(top_shell, (caddr_t) &app_data,
 					 resources, XtNumber(resources),
 					 (ArgList) NULL, 0);
 
-	if ((cdInfoDir == NULL) && ((s=getenv("XCDINFODIR")) != NULL))
-	    cdInfoDir = strdup(s);
+	if ((app_data.cdInfoDir == NULL) && ((s=getenv("XCDINFODIR")) != NULL))
+	    app_data.cdInfoDir = strdup(s);
 
 	top_form_widget = XtCreateWidget("mainForm", formWidgetClass,
 						 top_shell,
