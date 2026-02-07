--- control/affirm.c.orig	Tue Jul 12 02:55:50 1988
+++ control/affirm.c	Fri Jun 15 02:05:02 2007
@@ -9,6 +9,7 @@
 # include	"co_class.h"
 # include	<sys/time.h>
 # include	<assert.h>
+# include	<string.h>
 
 /*
  *	affirm window on screen
@@ -33,6 +34,9 @@
 static Window	affirm, ok, cancel;
 extern	GC	co_fore_gc;
 static int	OKstate, CANCELstate;
+
+static int redisplayLabel();
+
 
 int
 co_affirm(title, parent)
