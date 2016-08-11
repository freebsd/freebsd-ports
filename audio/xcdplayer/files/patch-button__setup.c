
$NetBSD: pkgsrc/audio/xcdplayer/patches/patch-ad,v 1.4 2005/12/11 20:48:46 joerg Exp $

--- button_setup.c.orig	1993-01-12 18:59:47 UTC
+++ button_setup.c
@@ -20,6 +20,9 @@
 # include <X11/Xaw/Toggle.h>
 
 # include "cdrom_globs.h"
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
+# include "cdrom_freebsd.h"
+#endif
 #ifdef sun
 # include "cdrom_sun.h"
 #endif
@@ -44,6 +47,23 @@
 # include "ff.xbm"
 # include "pgm.xbm"
 
+void     title_dialog_setup();
+static	void     play_button_setup();
+static	void     stop_button_setup();
+static	void     pause_button_setup();
+static	void     prev_button_setup();
+static	void     next_button_setup();
+static	void     eject_button_setup();
+#ifdef sgi
+void     audio_button_setup();
+#endif
+static	void     quit_button_setup();
+static	void     cycle_button_setup();
+static	void     shuffle_button_setup();
+static	void     rew_button_setup();
+static	void     ff_button_setup();
+static	void     pgm_button_setup();
+void     buttons_reset();
 
 static Widget	buttons_form_widget;
 static Widget	play_button_widget;
@@ -72,25 +92,6 @@ button_setup(parent_widget)
 {
 	Arg		args[1];
 
-	extern void	title_dialog_setup();
-	extern void	play_button_setup();
-	extern void	stop_button_setup();
-	extern void	pause_button_setup();
-	extern void	prev_button_setup();
-	extern void	next_button_setup();
-	extern void	eject_button_setup();
-#ifdef sgi
-	extern void	audio_button_setup();
-#endif
-	extern void	quit_button_setup();
-	extern void	cycle_button_setup();
-	extern void	shuffle_button_setup();
-	extern void	rew_button_setup();
-	extern void	ff_button_setup();
-	extern void	pgm_button_setup();
-	extern void	buttons_reset();
-
-
 	buttons_form_widget = XtCreateManagedWidget("buttonsForm",
 						    formWidgetClass,
 						    parent_widget,
