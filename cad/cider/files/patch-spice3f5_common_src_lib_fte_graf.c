--- spice3f5/common/src/lib/fte/graf.c.orig	1994-01-29 18:46:21 UTC
+++ spice3f5/common/src/lib/fte/graf.c
@@ -49,6 +49,9 @@ static char *ticlist = ticbuf;
 #define MAXTICS 100
 double *readtics();
 
+static int drawlegend();
+static int gr_resize_internal();
+
 #define XFACTOR 2       /* How much to expand the X scale during iplot. */
 #define YFACTOR 1.5     /* How much to expand the Y scale during iplot. */
 
