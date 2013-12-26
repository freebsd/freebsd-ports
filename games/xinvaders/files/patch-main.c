--- main.c.orig
+++ main.c
@@ -38,55 +38,6 @@
     {"-debug",	"*debug",	XrmoptionNoArg,	NULL},
 };
 
-static XtResource resources[] = {
-    {XtNwidth, XtCWidth, XtRInt, sizeof(int),
-	 (Cardinal)&width, XtRImmediate, (caddr_t) VWIDTH},
-    {XtNheight, XtCHeight, XtRInt, sizeof(int),
-	 (Cardinal)&height, XtRImmediate, (caddr_t) VHEIGHT},
-    {"debug", "Debug", XtRBoolean, sizeof(Boolean),
-	 (Cardinal)&debug, XtRString, "off"},
-    {"font", "Font", XtRString, sizeof(String),
-	 (Cardinal)&vaderfont, XtRString, (String)"9x15"},
-    {"scale", "Scale", XtRInt, sizeof(int),
-	 (Cardinal)&scale, XtRImmediate, (caddr_t) 2},
-    {"basewait", "BaseWait", XtRInt, sizeof(int),
-	 (Cardinal)&basewait, XtRImmediate, (caddr_t) 10},
-    {"vaderwait", "VaderWait", XtRInt, sizeof(int),
-	 (Cardinal)&vaderwait, XtRImmediate, (caddr_t) 300},
-    {"spacerwait", "SpacerWait", XtRInt, sizeof(int),
-	 (Cardinal)&spacerwait, XtRImmediate, (caddr_t) 50},
-    {"shotwait", "ShotWait", XtRInt, sizeof(int),
-	 (Cardinal)&shotwait, XtRImmediate, (caddr_t) 10},
-    {"vshotwait", "VshotWait", XtRInt, sizeof(int),
-	 (Cardinal)&vshotwait, XtRImmediate, (caddr_t) 30},
-    {"basecolor", "BaseColor", XtRPixel, sizeof(Pixel),
-	 (Cardinal)&basepixel, XtRString, "cyan"},
-    {"spacercolor", "SpacerColor", XtRPixel, sizeof(Pixel),
-	 (Cardinal)&spacerpixel, XtRString, "gray"},
-    {"buildingcolor", "BuildingColor", XtRPixel, sizeof(Pixel),
-	 (Cardinal)&buildingpixel, XtRString, "yellow"},
-    {"vader1color", "Vader1Color", XtRPixel, sizeof(Pixel),
-	 (Cardinal)&vader1pixel, XtRString, "blue"},
-    {"vader2color", "Vader2Color", XtRPixel, sizeof(Pixel),
-	 (Cardinal)&vader2pixel, XtRString, "green"},
-    {"vader3color", "Vader3Color", XtRPixel, sizeof(Pixel),
-	 (Cardinal)&vader3pixel, XtRString, "red"},
-    {"shotcolor", "ShotColor", XtRPixel, sizeof(Pixel),
-	 (Cardinal)&shotpixel, XtRString, "lavender"},
-    {"vshotcolor", "VshotColor", XtRPixel, sizeof(Pixel),
-	 (Cardinal)&vshotpixel, XtRString, "orange"},
-    {"scorecolor", "ScoreColor", XtRPixel, sizeof(Pixel),
-	 (Cardinal)&scorepixel, XtRString, "white"},
-    {"maxshots", "MaxShots", XtRInt, sizeof(int),
-	 (Cardinal) &maxshots, XtRImmediate, (caddr_t) 1},
-    {"maxvshots", "MaxVshots", XtRInt, sizeof(int),
-	 (Cardinal) &maxvshots, XtRImmediate, (caddr_t) 6},
-    {"defaultfore", "DefaultFore", XtRPixel, sizeof(Pixel),
-	 (Cardinal) &defaultfore, XtRString, "white"},
-    {"defaultback", "DefaultBack", XtRPixel, sizeof(Pixel),
-	 (Cardinal) &defaultback, XtRString, "black"},
-};
-
 
 /*ARGSUSED*/
 static void CvtStringToFloat(args, num_args, fromVal, toVal)
@@ -141,13 +92,62 @@
   return w;
 }
 
-int main(Cardinal argc, char **argv)
+int main(int argc, char **argv)
 {
   static Arg args[10];
   int n;
   Widget form, button;
   /* extern WidgetClass labelwidgetclass; */
 
+  XtResource resources[] = {
+    {XtNwidth, XtCWidth, XtRInt, sizeof(int),
+	 (Cardinal)&width, XtRImmediate, (caddr_t) VWIDTH},
+    {XtNheight, XtCHeight, XtRInt, sizeof(int),
+	 (Cardinal)&height, XtRImmediate, (caddr_t) VHEIGHT},
+    {"debug", "Debug", XtRBoolean, sizeof(Boolean),
+	 (Cardinal)&debug, XtRString, "off"},
+    {"font", "Font", XtRString, sizeof(String),
+	 (Cardinal)&vaderfont, XtRString, (String)"9x15"},
+    {"scale", "Scale", XtRInt, sizeof(int),
+	 (Cardinal)&scale, XtRImmediate, (caddr_t) 2},
+    {"basewait", "BaseWait", XtRInt, sizeof(int),
+	 (Cardinal)&basewait, XtRImmediate, (caddr_t) 10},
+    {"vaderwait", "VaderWait", XtRInt, sizeof(int),
+	 (Cardinal)&vaderwait, XtRImmediate, (caddr_t) 300},
+    {"spacerwait", "SpacerWait", XtRInt, sizeof(int),
+	 (Cardinal)&spacerwait, XtRImmediate, (caddr_t) 50},
+    {"shotwait", "ShotWait", XtRInt, sizeof(int),
+	 (Cardinal)&shotwait, XtRImmediate, (caddr_t) 10},
+    {"vshotwait", "VshotWait", XtRInt, sizeof(int),
+	 (Cardinal)&vshotwait, XtRImmediate, (caddr_t) 30},
+    {"basecolor", "BaseColor", XtRPixel, sizeof(Pixel),
+	 (Cardinal)&basepixel, XtRString, "cyan"},
+    {"spacercolor", "SpacerColor", XtRPixel, sizeof(Pixel),
+	 (Cardinal)&spacerpixel, XtRString, "gray"},
+    {"buildingcolor", "BuildingColor", XtRPixel, sizeof(Pixel),
+	 (Cardinal)&buildingpixel, XtRString, "yellow"},
+    {"vader1color", "Vader1Color", XtRPixel, sizeof(Pixel),
+	 (Cardinal)&vader1pixel, XtRString, "blue"},
+    {"vader2color", "Vader2Color", XtRPixel, sizeof(Pixel),
+	 (Cardinal)&vader2pixel, XtRString, "green"},
+    {"vader3color", "Vader3Color", XtRPixel, sizeof(Pixel),
+	 (Cardinal)&vader3pixel, XtRString, "red"},
+    {"shotcolor", "ShotColor", XtRPixel, sizeof(Pixel),
+	 (Cardinal)&shotpixel, XtRString, "lavender"},
+    {"vshotcolor", "VshotColor", XtRPixel, sizeof(Pixel),
+	 (Cardinal)&vshotpixel, XtRString, "orange"},
+    {"scorecolor", "ScoreColor", XtRPixel, sizeof(Pixel),
+	 (Cardinal)&scorepixel, XtRString, "white"},
+    {"maxshots", "MaxShots", XtRInt, sizeof(int),
+	 (Cardinal) &maxshots, XtRImmediate, (caddr_t) 1},
+    {"maxvshots", "MaxVshots", XtRInt, sizeof(int),
+	 (Cardinal) &maxvshots, XtRImmediate, (caddr_t) 6},
+    {"defaultfore", "DefaultFore", XtRPixel, sizeof(Pixel),
+	 (Cardinal) &defaultfore, XtRString, "white"},
+    {"defaultback", "DefaultBack", XtRPixel, sizeof(Pixel),
+	 (Cardinal) &defaultback, XtRString, "black"},
+};
+
   setlocale(LC_ALL, "");
   textdomain(PACKAGE);
 
