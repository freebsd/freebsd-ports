--- interface/xaw_i.c.orig	2004-09-27 08:40:14.000000000 +0900
+++ interface/xaw_i.c	2007-07-04 01:31:24.000000000 +0900
@@ -261,7 +261,7 @@
 String bitmapdir = XAW_BITMAP_DIR;
 Boolean arrangetitle,savelist;
 static char **current_flist = NULL;
-static int voices = 0, last_voice = 0, voices_num_width;
+static int xaw_i_voices = 0, last_voice = 0, voices_num_width;
 static int maxentry_on_a_menu = 0,submenu_n = 0;
 #define OPTIONS_WINDOW 1
 #define FLIST_WINDOW 2
@@ -1329,7 +1329,7 @@
     c= *(local_buf+1);
     n= atoi(local_buf+2);
     if(c == 'L')
-      voices = n;
+      xaw_i_voices = n;
     else
       last_voice = n;
     if(IsTracePlaying()) drawVoices();
@@ -2070,7 +2070,7 @@
   XSetForeground(disp, gct, tracecolor);
   XFillRectangle(disp,XtWindow(trace),gct,voices_num_width +4,
                  MAX_XAW_MIDI_CHANNELS*BAR_SPACE+TRACEV_OFS+1,VOICENUM_WIDTH,TRACE_FOOT);  
-  sprintf(local_buf, "%3d/%d", last_voice, voices);
+  sprintf(local_buf, "%3d/%d", last_voice, xaw_i_voices);
   XSetForeground(disp, gct, capcolor);  
   XDrawString(disp, XtWindow(trace),gct,voices_num_width+6,
               MAX_XAW_MIDI_CHANNELS*BAR_SPACE+TRACEV_OFS+16,local_buf,strlen(local_buf));
@@ -2326,7 +2326,7 @@
           if (c == LF || c == EOF || i > SSIZE) break;
           *p++ = c;
         }
-        *p = (char)NULL;
+        *p = '\0';
         if (0 != strncasecmp(s, "set ", 4)) continue;
         switch (configcmp(s+4, &k)) {
         case S_RepeatPlay:
