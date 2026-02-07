--- main.c.orig	2000-09-10 22:32:16 UTC
+++ main.c
@@ -26,7 +26,6 @@ Wed May  8 1991
 #include <X11/IntrinsicP.h>
 #include <X11/Label.h>
 #endif
-static int width, height;		/* Size of window. */
 
 #ifdef XFILESEARCHPATH
 static void AddPathToSearchPath();
@@ -40,51 +39,51 @@ static XrmOptionDescRec table[] = {
 
 static XtResource resources[] = {
     {XtNwidth, XtCWidth, XtRInt, sizeof(int),
-	 (Cardinal)&width, XtRImmediate, (caddr_t) VWIDTH},
+	 XtOffsetOf(AppData, width), XtRImmediate, (caddr_t) VWIDTH},
     {XtNheight, XtCHeight, XtRInt, sizeof(int),
-	 (Cardinal)&height, XtRImmediate, (caddr_t) VHEIGHT},
+	 XtOffsetOf(AppData, height), XtRImmediate, (caddr_t) VHEIGHT},
     {"debug", "Debug", XtRBoolean, sizeof(Boolean),
-	 (Cardinal)&debug, XtRString, "off"},
+	 XtOffsetOf(AppData, debug), XtRString, "off"},
     {"font", "Font", XtRString, sizeof(String),
-	 (Cardinal)&vaderfont, XtRString, (String)"9x15"},
+	 XtOffsetOf(AppData, vaderfont), XtRString, (String)"9x15"},
     {"scale", "Scale", XtRInt, sizeof(int),
-	 (Cardinal)&scale, XtRImmediate, (caddr_t) 2},
+	 XtOffsetOf(AppData, scale), XtRImmediate, (caddr_t) 2},
     {"basewait", "BaseWait", XtRInt, sizeof(int),
-	 (Cardinal)&basewait, XtRImmediate, (caddr_t) 10},
+	 XtOffsetOf(AppData, basewait), XtRImmediate, (caddr_t) 10},
     {"vaderwait", "VaderWait", XtRInt, sizeof(int),
-	 (Cardinal)&vaderwait, XtRImmediate, (caddr_t) 300},
+	 XtOffsetOf(AppData, vaderwait), XtRImmediate, (caddr_t) 300},
     {"spacerwait", "SpacerWait", XtRInt, sizeof(int),
-	 (Cardinal)&spacerwait, XtRImmediate, (caddr_t) 50},
+	 XtOffsetOf(AppData, spacerwait), XtRImmediate, (caddr_t) 50},
     {"shotwait", "ShotWait", XtRInt, sizeof(int),
-	 (Cardinal)&shotwait, XtRImmediate, (caddr_t) 10},
+	 XtOffsetOf(AppData, shotwait), XtRImmediate, (caddr_t) 10},
     {"vshotwait", "VshotWait", XtRInt, sizeof(int),
-	 (Cardinal)&vshotwait, XtRImmediate, (caddr_t) 30},
+	 XtOffsetOf(AppData, vshotwait), XtRImmediate, (caddr_t) 30},
     {"basecolor", "BaseColor", XtRPixel, sizeof(Pixel),
-	 (Cardinal)&basepixel, XtRString, "cyan"},
+	 XtOffsetOf(AppData, basepixel), XtRString, "cyan"},
     {"spacercolor", "SpacerColor", XtRPixel, sizeof(Pixel),
-	 (Cardinal)&spacerpixel, XtRString, "gray"},
+	 XtOffsetOf(AppData, spacerpixel), XtRString, "gray"},
     {"buildingcolor", "BuildingColor", XtRPixel, sizeof(Pixel),
-	 (Cardinal)&buildingpixel, XtRString, "yellow"},
+	 XtOffsetOf(AppData, buildingpixel), XtRString, "yellow"},
     {"vader1color", "Vader1Color", XtRPixel, sizeof(Pixel),
-	 (Cardinal)&vader1pixel, XtRString, "blue"},
+	 XtOffsetOf(AppData, vader1pixel), XtRString, "blue"},
     {"vader2color", "Vader2Color", XtRPixel, sizeof(Pixel),
-	 (Cardinal)&vader2pixel, XtRString, "green"},
+	 XtOffsetOf(AppData, vader2pixel), XtRString, "green"},
     {"vader3color", "Vader3Color", XtRPixel, sizeof(Pixel),
-	 (Cardinal)&vader3pixel, XtRString, "red"},
+	 XtOffsetOf(AppData, vader3pixel), XtRString, "red"},
     {"shotcolor", "ShotColor", XtRPixel, sizeof(Pixel),
-	 (Cardinal)&shotpixel, XtRString, "lavender"},
+	 XtOffsetOf(AppData, shotpixel), XtRString, "lavender"},
     {"vshotcolor", "VshotColor", XtRPixel, sizeof(Pixel),
-	 (Cardinal)&vshotpixel, XtRString, "orange"},
+	 XtOffsetOf(AppData, vshotpixel), XtRString, "orange"},
     {"scorecolor", "ScoreColor", XtRPixel, sizeof(Pixel),
-	 (Cardinal)&scorepixel, XtRString, "white"},
+	 XtOffsetOf(AppData, scorepixel), XtRString, "white"},
     {"maxshots", "MaxShots", XtRInt, sizeof(int),
-	 (Cardinal) &maxshots, XtRImmediate, (caddr_t) 1},
+	 XtOffsetOf(AppData, maxshots), XtRImmediate, (caddr_t) 1},
     {"maxvshots", "MaxVshots", XtRInt, sizeof(int),
-	 (Cardinal) &maxvshots, XtRImmediate, (caddr_t) 6},
+	 XtOffsetOf(AppData, maxvshots), XtRImmediate, (caddr_t) 6},
     {"defaultfore", "DefaultFore", XtRPixel, sizeof(Pixel),
-	 (Cardinal) &defaultfore, XtRString, "white"},
+	 XtOffsetOf(AppData, defaultfore), XtRString, "white"},
     {"defaultback", "DefaultBack", XtRPixel, sizeof(Pixel),
-	 (Cardinal) &defaultback, XtRString, "black"},
+	 XtOffsetOf(AppData, defaultback), XtRString, "black"},
 };
 
 
@@ -141,7 +140,7 @@ caddr_t data;
   return w;
 }
 
-int main(Cardinal argc, char **argv)
+int main(int argc, char **argv)
 {
   static Arg args[10];
   int n;
@@ -161,25 +160,25 @@ int main(Cardinal argc, char **argv)
 			  &argc, argv);
   dpy = XtDisplay(toplevel);
   XtAddConverter(XtRString, XtRFloat, CvtStringToFloat, NULL, 0);
-  XtGetApplicationResources(toplevel, (caddr_t) NULL, 
+  XtGetApplicationResources(toplevel, (caddr_t) &app_data, 
 			    resources, XtNumber(resources),
 			    NULL, (Cardinal) 0);
-  AddResource("*background", &defaultback);
+  AddResource("*background", &app_data.defaultback);
   if (DisplayCells(dpy, DefaultScreen(dpy)) <= 2)
     {
-      basepixel = defaultfore;
-      buildingpixel = defaultfore;
-      vader1pixel = defaultfore;
-      vader2pixel = defaultfore;
-      vader3pixel = defaultfore;
-      shotpixel = defaultfore;
-      vshotpixel = defaultfore;
-      scorepixel = defaultfore;
+      app_data.basepixel = app_data.defaultfore;
+      app_data.buildingpixel = app_data.defaultfore;
+      app_data.vader1pixel = app_data.defaultfore;
+      app_data.vader2pixel = app_data.defaultfore;
+      app_data.vader3pixel = app_data.defaultfore;
+      app_data.shotpixel = app_data.defaultfore;
+      app_data.vshotpixel = app_data.defaultfore;
+      app_data.scorepixel = app_data.defaultfore;
     }
-  if (scale<1) scale = 1;
-  if (scale>2) scale = 2;
-  width = scale*VWIDTH;
-  height = scale*VHEIGHT;
+  if (app_data.scale<1) app_data.scale = 1;
+  if (app_data.scale>2) app_data.scale = 2;
+  app_data.width = app_data.scale*VWIDTH;
+  app_data.height = app_data.scale*VHEIGHT;
 
   form = XtCreateManagedWidget ("form", formWidgetClass,
 				toplevel, NULL, 0);
@@ -189,8 +188,8 @@ int main(Cardinal argc, char **argv)
   XtSetArg (args[n], XtNright, XtChainLeft); n++;
   XtSetArg (args[n], XtNtop, XtChainTop); n++;
   XtSetArg (args[n], XtNbottom, XtChainTop); n++;
-  XtSetArg (args[n], XtNwidth, width); n++;
-  XtSetArg (args[n], XtNheight, height); n++;
+  XtSetArg (args[n], XtNwidth, app_data.width); n++;
+  XtSetArg (args[n], XtNheight, app_data.height); n++;
   
   gamewidget = (VadersWidget)
     XtCreateManagedWidget("field", vadersWidgetClass, form, args, n);
@@ -204,29 +203,29 @@ int main(Cardinal argc, char **argv)
   XtSetArg (args[n], XtNbottom, XtChainTop); n++;
   XtSetArg (args[n], XtNfromHoriz, gamewidget); n++;
   XtSetArg (args[n], XtNhorizDistance, 5); n++;
-  XtSetArg (args[n], XtNwidth, scale*IWIDTH); n++;
-  XtSetArg (args[n], XtNheight, height/2); n++;
+  XtSetArg (args[n], XtNwidth, app_data.scale*IWIDTH); n++;
+  XtSetArg (args[n], XtNheight, app_data.height/2); n++;
   
   labelwidget = (VadersWidget)
     XtCreateManagedWidget("label", vadersWidgetClass, form, args, n);
 
   pausebutton = MakeCommandButton(form, "pause", Pause, labelwidget, gamewidget, NULL);
   XtSetArg(args[0], XtNlabel,_(" Start"));
-  XtSetArg(args[1], XtNforeground, defaultfore);
-  XtSetArg(args[2], XtNbackground, defaultback);
-  XtSetArg(args[3], XtNborderColor, defaultfore);
+  XtSetArg(args[1], XtNforeground, app_data.defaultfore);
+  XtSetArg(args[2], XtNbackground, app_data.defaultback);
+  XtSetArg(args[3], XtNborderColor, app_data.defaultfore);
   XtSetValues(pausebutton, args, 4);
   button = MakeCommandButton(form, "quit", Quit, pausebutton, gamewidget, NULL);
   XtSetArg(args[0], XtNlabel,_(" Quit "));
-  XtSetArg(args[1], XtNforeground, defaultfore);
-  XtSetArg(args[2], XtNbackground, defaultback);
-  XtSetArg(args[3], XtNborderColor, defaultfore);
+  XtSetArg(args[1], XtNforeground, app_data.defaultfore);
+  XtSetArg(args[2], XtNbackground, app_data.defaultback);
+  XtSetArg(args[3], XtNborderColor, app_data.defaultfore);
   XtSetValues(button, args, 4);
   infobutton = MakeCommandButton(form, "info", ShowInfo, button, gamewidget, NULL);
   XtSetArg(args[0], XtNlabel,_(" Info "));
-  XtSetArg(args[1], XtNforeground, defaultfore);
-  XtSetArg(args[2], XtNbackground, defaultback);
-  XtSetArg(args[3], XtNborderColor, defaultfore);
+  XtSetArg(args[1], XtNforeground, app_data.defaultfore);
+  XtSetArg(args[2], XtNbackground, app_data.defaultback);
+  XtSetArg(args[3], XtNborderColor, app_data.defaultfore);
   XtSetValues(infobutton, args, 4);
 
   XtRealizeWidget(toplevel);
@@ -280,7 +279,7 @@ char *path;
 }
 #endif
 
-#ifdef sparc
+#ifdef sun
 XShapeCombineMask()
 {}
 
