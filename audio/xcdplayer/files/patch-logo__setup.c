
$FreeBSD$

--- logo_setup.c.orig	Tue Jan 12 19:59:46 1993
+++ logo_setup.c	Mon Aug 25 00:38:35 2003
@@ -28,6 +28,9 @@
 # include <stdio.h>
 
 # include "cdrom_globs.h"
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
+# include "cdrom_freebsd.h"
+#endif
 #ifdef sun
 # include "cdrom_sun.h"
 #endif
@@ -43,6 +46,8 @@
 
 void	Done();
 
+extern AppData app_data;
+
 static Widget	track_button_widget;
 static Widget	timer_button_widget;
 static Widget	volume_scroll_widget;
@@ -55,19 +60,19 @@
 Widget		title_done_widget;
 
 static int	vol;
+extern void     leds_label_setup();
+static void     cb_track_button();
+static void     cb_timer_button();
+static void     volume_jump_proc();
+static void     volume_scroll_proc();
+static void     popup_title_dialog();
+static void     popdown_title_dialog();
+
 
 void
 logo_setup(parent_widget)
 	Widget		parent_widget;
 {
-	extern void	leds_label_setup();
-	extern void	cb_track_button();
-	extern void	cb_timer_button();
-	extern void	volume_jump_proc();
-	extern void	volume_scroll_proc();
-	extern void	popup_title_dialog();
-	extern void	popdown_title_dialog();
-
 	Widget		version_label_widget;
 	char		version_string[80];
 
@@ -126,15 +131,16 @@
 
 	track_button_update();
 
-	if (display_timer == True)
+	if (app_data.display_timer == True) {
 		timer_button_widget = XtCreateManagedWidget("timerButton",
 						    	   toggleWidgetClass,
 							   logo_form_widget,
 							   (ArgList) NULL, 0);
 
-	XtAddCallback(timer_button_widget, XtNcallback, cb_timer_button, 0);
-
-	timer_button_update();
+		XtAddCallback(timer_button_widget, XtNcallback, 
+			     cb_timer_button, 0);
+		timer_button_update();
+	}
 	thumb_pixmap = XCreateBitmapFromData(XtDisplay(logo_form_widget),
 						  rootwin(logo_form_widget),
 						  thumb_bits,
@@ -171,10 +177,10 @@
 
 #ifdef sgi
 	if ((vol = cdrom_get_volume()) == 0) {
-		vol = (int) ((MAXVOL - volbase) * 0.75) + volbase;
+		vol = (int) ((MAXVOL - app_data.volbase) * 0.75) + app_data.volbase;
 	}
 #else
-	vol = (int) ((MAXVOL - volbase) * 0.75) + volbase;
+	vol = (int) ((MAXVOL - app_data.volbase) * 0.75) + app_data.volbase;
 #endif
 	cdrom_volume(vol, vol); 
 #ifdef sgi
@@ -356,7 +362,7 @@
 	Arg		args[1];
 	Boolean		state;
 
-	if (display_timer == False)
+	if (app_data.display_timer == False)
 		return;
 
 	    if ((cdi.state & CDROM_STATE_PAUSE) == 0)
@@ -413,7 +419,7 @@
 	vol = PCT2VAL(*(float *)percent);
 #else
 	vol = (*(float *) percent) * MAXVOL;
-	vol = (vol * volpcent) + volbase;
+	vol = (vol * app_data.volpcent) + app_data.volbase;
 #endif
 
 	if (vol > MAXVOL)
