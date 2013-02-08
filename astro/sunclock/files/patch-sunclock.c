--- sunclock.c
+++ sunclock.c
@@ -113,7 +113,6 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <sys/types.h>
-#include <sys/timeb.h>
 #include <sys/stat.h>
 #include <string.h>
 #include <X11/Xatom.h>
@@ -127,7 +126,6 @@
  *  external routines
  */
 
-extern long     time();
 #ifdef NEW_CTIME
 extern char *   timezone();
 #endif
@@ -2197,8 +2195,8 @@
 
         if (!Context->mark1.city) return;
 
-        time(&Context->time);
-        gtime = Context->time + Context->jump;
+        time(&Context->footime);
+        gtime = Context->footime + Context->jump;
 
         /* Get local time at given location */
         setTZ(Context->mark1.city);
@@ -2335,20 +2333,11 @@
         char            s[128];
         char            slat[20], slon[20], slatp[20], slonp[20];
         double          dist;
-#ifdef NEW_CTIME
-        struct timeb            tp;
-
-        if (ftime(&tp) == -1) {
-                fprintf(stderr, "%s: ftime failed: ", ProgName);
-                perror("");
-                exit(1);
-        }
-#endif
 
 	if (!Context->flags.mapped) return;
 
-        time(&Context->time);
-        gtime = Context->time + Context->jump;
+        time(&Context->footime);
+        gtime = Context->footime + Context->jump;
 
         if (!Context->wintype) {
                 char num[80];
@@ -2696,7 +2685,7 @@
 
         Context->bits = 0;
         Context->flags.update = 4;
-        Context->time = 0L;
+        Context->footime = 0L;
         Context->projtime = -1L;
         Context->roottime = -1L;
         Context->animtime = -1L;
@@ -3918,7 +3907,7 @@
 
         if (button_pressed) return;
 
-        time(&Context->time);
+        time(&Context->footime);
 
 	erase_obj = 1;
 	if (Context->flags.colorlevel == MONOCHROME ||
@@ -3926,10 +3915,10 @@
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
@@ -3946,10 +3935,10 @@
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
@@ -4557,8 +4546,8 @@
      hw = Context->geom.height;
      if (do_root == 2) hw += Context->hstrip;
 
-     if (abs(Context->time - Context->roottime) >= root_period)
-        Context->roottime = Context->time;
+     if (abs(Context->footime - Context->roottime) >= root_period)
+        Context->roottime = Context->footime;
      else
         if (do_root == 2 && mode==0 && rootpix) update = 0;
 
@@ -4569,7 +4558,7 @@
         XSetForeground(dpy, Context->gdata->wingc, 
                          Context->gdata->pixel[ROOTCOLOR]);
         XFillRectangle(dpy, rootpix, Context->gdata->wingc, 0, 0, wr, hr);
-        srandom(Context->time);
+        srandom(Context->footime);
         if (random_rootpos) {
            rootdx = (double)(random() % 10001)/10000.0;
            rootdy = (double)(random() % 10001)/10000.0;
@@ -5542,7 +5531,7 @@
              Context->flags.update = 2;
              break;
            case XK_w: 
-             if (Context->time<=last_time+2) return;
+             if (Context->footime<=last_time+2) return;
              if (do_menu) do_menu = -1;
              if (do_filesel) do_filesel = -1;
              if (do_zoom) do_zoom = -1;
@@ -5958,9 +5947,9 @@
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
