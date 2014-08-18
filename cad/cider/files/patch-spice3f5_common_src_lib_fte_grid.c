--- spice3f5/common/src/lib/fte/grid.c.orig	1994-01-29 18:47:59 UTC
+++ spice3f5/common/src/lib/fte/grid.c
@@ -19,6 +19,9 @@ Copyright 1990 Regents of the University
 #define RAD_TO_DEG	(180.0 / M_PI)
 #define LABEL_CHARS	20
 
+static int drawlingrid();
+static int drawloggrid();
+
 static double *lingrid(), *loggrid();
 static void polargrid(), smithgrid();
 static void drawpolargrid( );
