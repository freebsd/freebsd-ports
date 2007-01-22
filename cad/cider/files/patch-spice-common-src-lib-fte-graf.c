--- spice/common/src/lib/fte/graf.c.orig	Sun Jan 30 03:46:21 1994
+++ spice/common/src/lib/fte/graf.c	Fri Dec 22 20:12:25 2006
@@ -49,6 +49,9 @@
 #define MAXTICS 100
 double *readtics();
 
+static int drawlegend();
+static int gr_resize_internal();
+
 #define XFACTOR 2       /* How much to expand the X scale during iplot. */
 #define YFACTOR 1.5     /* How much to expand the Y scale during iplot. */
 
