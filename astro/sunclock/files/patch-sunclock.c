--- sunclock.c.orig	Wed Aug  8 07:53:14 2001
+++ sunclock.c	Sat Dec  8 21:24:46 2001
@@ -125,7 +125,6 @@
  *  external routines
  */
 
-extern long     time();
 #ifdef NEW_CTIME
 extern char *   timezone();
 #endif
@@ -2062,8 +2061,8 @@
 
         if (!Context->mark1.city) return;
 
-        time(&Context->time);
-        gtime = Context->time + Context->jump;
+        time(&Context->footime);
+        gtime = Context->footime + Context->jump;
 
         /* Get local time at given location */
         setTZ(Context->mark1.city);
@@ -2212,8 +2211,8 @@
 
 	if (!Context->flags.mapped) return;
 
-        time(&Context->time);
-        gtime = Context->time + Context->jump;
+        time(&Context->footime);
+        gtime = Context->footime + Context->jump;
 
         if (!Context->wintype) {
                 char num[80];
@@ -2542,7 +2541,7 @@
 
         Context->bits = 0;
         Context->flags.update = 4;
-        Context->time = 0L;
+        Context->footime = 0L;
         Context->projtime = -1L;
         Context->roottime = -1L;
         Context->animtime = -1L;
@@ -3708,7 +3707,7 @@
 
         if (button_pressed) return;
 
-        time(&Context->time);
+        time(&Context->footime);
 
 	erase_obj = 1;
 	if (Context->flags.colorlevel == MONOCHROME ||
@@ -3716,10 +3715,10 @@
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
@@ -3736,10 +3735,10 @@
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
@@ -4341,8 +4340,8 @@
      hw = Context->geom.height;
      if (do_root == 2) hw += Context->hstrip;
 
-     if (abs(Context->time - Context->roottime) >= root_period)
-        Context->roottime = Context->time;
+     if (abs(Context->footime - Context->roottime) >= root_period)
+        Context->roottime = Context->footime;
      else
         if (do_root == 2 && mode==0 && rootpix) update = 0;
 
@@ -4353,7 +4352,7 @@
         XSetForeground(dpy, Context->gdata->wingc, 
                          Context->gdata->pixel[ROOTCOLOR]);
         XFillRectangle(dpy, rootpix, Context->gdata->wingc, 0, 0, wr, hr);
-        srandom(Context->time);
+        srandom(Context->footime);
         if (random_rootpos) {
            rootdx = (double)(random() % 10001)/10000.0;
            rootdy = (double)(random() % 10001)/10000.0;
@@ -5299,13 +5298,13 @@
              Context->flags.update = 2;
              break;
            case XK_w: 
-             if (Context->time<=last_time+2) return;
+             if (Context->footime<=last_time+2) return;
              if (do_menu) do_menu = -1;
              if (do_filesel) do_filesel = -1;
              if (do_zoom) do_zoom = -1;
              if (do_option) do_option = -1;
              buildMap(Context, 1, 1);
-             last_time = Context->time;
+             last_time = Context->footime;
 	     keysym = ' ';
              break;
            case XK_r:
@@ -5616,9 +5615,9 @@
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
