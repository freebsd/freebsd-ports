--- sunclock.c.orig	Fri Oct  8 17:11:44 2004
+++ sunclock.c	Sun Nov 21 13:51:14 2004
@@ -125,7 +125,6 @@
  *  external routines
  */
 
-extern long     time();
 #ifdef NEW_CTIME
 extern char *   timezone();
 #endif
@@ -2164,8 +2163,8 @@
 
         if (!Context->mark1.city) return;
 
-        time(&Context->time);
-        gtime = Context->time + Context->jump;
+        time(&Context->footime);
+        gtime = Context->footime + Context->jump;
 
         /* Get local time at given location */
         setTZ(Context->mark1.city);
@@ -2314,8 +2313,8 @@
 
 	if (!Context->flags.mapped) return;
 
-        time(&Context->time);
-        gtime = Context->time + Context->jump;
+        time(&Context->footime);
+        gtime = Context->footime + Context->jump;
 
         if (!Context->wintype) {
                 char num[80];
@@ -2661,7 +2660,7 @@
 
         Context->bits = 0;
         Context->flags.update = 4;
-        Context->time = 0L;
+        Context->footime = 0L;
         Context->projtime = -1L;
         Context->roottime = -1L;
         Context->animtime = -1L;
@@ -3827,7 +3826,7 @@
 
         if (button_pressed) return;
 
-        time(&Context->time);
+        time(&Context->footime);
 
 	erase_obj = 1;
 	if (Context->flags.colorlevel == MONOCHROME ||
@@ -3835,10 +3834,10 @@
             drawSunAndMoon(Context);
         erase_obj = 0;
 
-        (void) sunParams(Context->time + Context->jump, 
+        (void) sunParams(Context->footime + Context->jump, 
               &Context->sunlon, &Context->sundec, NULL);
 
-        (void) phase(Context->time + Context->jump, 
+        (void) phase(Context->footime + Context->jump, 
               &Context->moondec, &Context->moonlon, 
               &junk,  &junk, &junk, &junk, &junk, &junk );
 	Context->moonlon = fixangle(Context->moonlon+180.0) - 180.0;
@@ -3855,10 +3854,10 @@
            update the illuminated area on the screen.   */
 
         if (Context->projtime < 0 || 
-            (Context->time - Context->projtime) > PROJINT ||
+            (Context->footime - Context->projtime) > PROJINT ||
             Context->noon != noon || Context->flags.update>=4) {
                 Context->flags.update = 2;
-                Context->projtime = Context->time;
+                Context->projtime = Context->footime;
                 Context->noon = noon;
                 Context->fnoon = fnoon;
                 moveNightArea(Context);
@@ -4466,8 +4465,8 @@
      hw = Context->geom.height;
      if (do_root == 2) hw += Context->hstrip;
 
-     if (abs(Context->time - Context->roottime) >= root_period)
-        Context->roottime = Context->time;
+     if (abs(Context->footime - Context->roottime) >= root_period)
+        Context->roottime = Context->footime;
      else
         if (do_root == 2 && mode==0 && rootpix) update = 0;
 
@@ -4478,7 +4477,7 @@
         XSetForeground(dpy, Context->gdata->wingc, 
                          Context->gdata->pixel[ROOTCOLOR]);
         XFillRectangle(dpy, rootpix, Context->gdata->wingc, 0, 0, wr, hr);
-        srandom(Context->time);
+        srandom(Context->footime);
         if (random_rootpos) {
            rootdx = (double)(random() % 10001)/10000.0;
            rootdy = (double)(random() % 10001)/10000.0;
@@ -5434,7 +5433,7 @@
              Context->flags.update = 2;
              break;
            case XK_w: 
-             if (Context->time<=last_time+2) return;
+             if (Context->footime<=last_time+2) return;
              if (do_menu) do_menu = -1;
              if (do_filesel) do_filesel = -1;
              if (do_zoom) do_zoom = -1;
@@ -5825,9 +5824,9 @@
               drawImageToRootWindow(Context, 0);
 	   XFlush(dpy);
 	   if (Context->flags.animate) {
-	      if (abs(Context->time-Context->animtime) >= 
+	      if (abs(Context->footime-Context->animtime) >= 
                   Context->flags.animperiod) {
-		 Context->animtime = Context->time;
+		 Context->animtime = Context->footime;
 	         Context->jump += progress_value[Context->flags.progress];
                  Context->flags.update = 4;
 	      }
