--- x.c.orig	2004-08-15 13:13:22 UTC
+++ x.c
@@ -104,7 +104,6 @@ static int is_allocated[STE_COLORS];
 unsigned long pixel_value_by_index[16];
 static unsigned char pixel_index[16];
 static int is_allocated[STE_COLORS];
-SCRDEF scr_def[3];
 static int scr_x, scr_y; /* x,y possition of STonX Main Window */
 
 /* some interesting events: */
@@ -980,6 +979,9 @@ void x_screen_open (void)
     scr_height = scr_def[shiftmod].h;
 
     strcpy(win_name, "STonX Main Window");
+#if SHIFT_PAUSE_EXITS
+    strcpy(win_name, "STonX  [Shift-Pause to quit]");
+#endif
 
     if ((display = XOpenDisplay (NULL)) == NULL)
     {
