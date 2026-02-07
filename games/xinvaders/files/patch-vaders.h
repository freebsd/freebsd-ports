--- vaders.h.orig	2000-09-10 22:32:40 UTC
+++ vaders.h
@@ -90,15 +90,82 @@ typedef struct _VadersRec {
 
 
 
+/*
+ * Application resources
+ */
+typedef struct {
+    int width, height;		/* Size of window. */
+    int scale;
+    Boolean debug;
 
+    /* Base info: */
+    int basewait;		/* Number of milliseconds to wait between */
+				/* moving base. */
+    Pixel basepixel;
+    Pixel buildingpixel;
+
+    /* Vader info  */
+    Pixel vader1pixel;
+    Pixel vader2pixel;
+    Pixel vader3pixel;
+    int vaderwait;		/* Number of milliseconds to wait between */
+				/* moving vaders. */
+
+    /* Spacer info */
+    Pixel spacerpixel;
+    int spacerwait;		/* Number of milliseconds to wait between */
+				/* moving spacers. */
+
+    /* Shot info */
+    Pixel shotpixel;
+    Pixel vshotpixel;
+    int shotwait;
+    int vshotwait;
+    int maxshots;		/* How many shots are allowed to exist at */
+				/* once. */
+    int maxvshots;		/* How many shots are allowed to exist at */
+				/* once. */
+
+    /* Score info */
+    Pixel scorepixel;
+
+    Pixel defaultfore, defaultback;
+
+    char *vaderfont;
+} AppData;
+
+ext AppData app_data;
+
+#ifndef MAIN
+#define scale		app_data.scale
+#define debug		app_data.debug
+#define basewait	app_data.basewait
+#define basepixel	app_data.basepixel
+#define buildingpixel	app_data.buildingpixel
+#define vader1pixel	app_data.vader1pixel
+#define vader2pixel	app_data.vader2pixel
+#define vader3pixel	app_data.vader3pixel
+#define vaderwait	app_data.vaderwait
+#define spacerpixel	app_data.spacerpixel
+#define spacerwait	app_data.spacerwait
+#define shotpixel	app_data.shotpixel
+#define vshotpixel	app_data.vshotpixel
+#define shotwait	app_data.shotwait
+#define vshotwait	app_data.vshotwait
+#define maxshots	app_data.maxshots
+#define maxvshots	app_data.maxvshots
+#define scorepixel	app_data.scorepixel
+#define defaultfore	app_data.defaultfore
+#define defaultback	app_data.defaultback
+#define vaderfont	app_data.vaderfont
+#endif
+
 /*
  * Actual vaders definitions.
  */
 
 ext Widget pausebutton, infobutton;
-ext int scale;
 
-ext Boolean debug;
 ext int level;
 
 ext Display *dpy;
@@ -111,54 +178,31 @@ ext int basesleft;
 
 /* Base info: */
 
-ext int basewait;		/* Number of milleseconds to wait between */
-				/* moving base. */
-
 ext XtIntervalId basetimerid;
 
-ext Pixel basepixel;
-ext Pixel buildingpixel;
-ext Boolean basedestroyed;	/* TRUE if the base is non-existant */
+extern Boolean basedestroyed;	/* TRUE if the base is non-existant */
 
 /* Vader info: */
 
 ext XtIntervalId vadertimerid;
-ext Pixel vader1pixel;
-ext Pixel vader2pixel;
-ext Pixel vader3pixel;
-ext int vaderwait;		/* Number of milleseconds to wait between */
-				/* moving vaders. */
 
 /* Spacer info */
 
-ext Pixel spacerpixel;
 ext XtIntervalId spacertimerid;
-ext int spacerwait;		/* Number of milliseconds to wait between */
-				/* moving spacers. */
 ext int spacerappear;		/* same, but for the interval between appearances */
 
-ext Boolean spacer_shown;    	/* Currnet_Spacer is something */
-ext int spacer_counter;		/* number of cycles to create a spacer */
+extern Boolean spacer_shown;    	/* Currnet_Spacer is something */
+extern int spacer_counter;		/* number of cycles to create a spacer */
 
 /* Shot info. */
 
 ext XtIntervalId shottimerid;
 ext XtIntervalId vshottimerid;
-ext Pixel shotpixel;
-ext Pixel vshotpixel;
-ext int shotwait;
-ext int vshotwait;
-ext int maxshots;		/* How many shots are allowed to exist at */
-				/* once. */
-ext int maxvshots;		/* How many shots are allowed to exist at */
-				/* once. */
-ext int numshots;		/* how many shots (from the base) there are right now. */
-ext int numvshots;		/* how many shots (from vaders) there are right now. */
+extern int numshots;		/* how many shots (from the base) there are right now. */
+extern int numvshots;		/* how many shots (from vaders) there are right now. */
 
 /* Score info */
 
-ext Pixel scorepixel;
-
 ext int bases, nextbonus, lastscore;
 extern int hiscore;
 
@@ -227,8 +271,5 @@ void InitShot();
 void MoveShots();
 void MoveVshots();
 void PaintAllShots();
-ext Pixel defaultfore, defaultback;
-
-ext char *vaderfont;
 
 #endif _vaders_h
