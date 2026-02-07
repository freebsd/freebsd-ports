
$NetBSD: pkgsrc/audio/xcdplayer/patches/patch-ak,v 1.4 2005/12/11 20:48:46 joerg Exp $

--- program.c.orig	1993-01-12 18:59:49 UTC
+++ program.c
@@ -27,10 +27,13 @@
 
 # include <stdio.h>
 # include <string.h>
-# include <malloc.h>
+# include <stdlib.h>
 
 # include "debug.h"
 # include "cdrom_globs.h"
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
+# include "cdrom_freebsd.h"
+#endif
 #ifdef sun
 # include "cdrom_sun.h"
 #endif
@@ -52,6 +55,15 @@ static	Widget	new_track_button;
 static	Boolean	adding_to_new_track = False;
 static	struct	prognode *current_node = NULL;
 
+static	void    cb_move_program_ptr();
+static	void    cb_clear_program();
+static	void    cb_cancel_program();
+static	void    cb_save_program();
+static	void    cb_trackbuttons();
+static	void    cb_add_10();
+static	void    cb_new_track();
+static	void    cb_program_all();
+
 void
 program_form_setup (parent_widget)
 	Widget	parent_widget;
@@ -67,15 +79,6 @@ program_form_setup (parent_widget)
 	Widget	save_button;
 	Widget	all_button;
 
-	extern	void	cb_move_program_ptr();
-	extern	void	cb_clear_program();
-	extern	void	cb_cancel_program();
-	extern	void	cb_save_program();
-	extern	void	cb_trackbuttons();
-	extern	void	cb_add_10();
-	extern	void	cb_new_track();
-	extern	void	cb_program_all();
-
 	/* 
 	 * create program form as a non-managed widget, because this 
 	 * form "pops up" when requested, as part of the main form, and
