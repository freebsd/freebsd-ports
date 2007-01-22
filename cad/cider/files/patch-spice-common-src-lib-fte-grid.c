--- spice/common/src/lib/fte/grid.c.orig	Sun Jan 30 03:47:59 1994
+++ spice/common/src/lib/fte/grid.c	Fri Dec 22 20:11:21 2006
@@ -19,6 +19,9 @@
 #define RAD_TO_DEG	(180.0 / M_PI)
 #define LABEL_CHARS	20
 
+static int drawlingrid();
+static int drawloggrid();
+
 static double *lingrid(), *loggrid();
 static void polargrid(), smithgrid();
 static void drawpolargrid( );
