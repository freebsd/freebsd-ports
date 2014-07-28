--- xroach.c.orig	1993-06-04 21:47:09.000000000 +0200
+++ xroach.c	2011-12-20 19:03:53.816175581 +0100
@@ -77,7 +77,7 @@
 int MarkHiddenRoaches();
 Pixel AllocNamedColor();
 
-void
+int
 main(ac, av)
 int ac;
 char *av[];
@@ -96,19 +96,23 @@
     /*
        Process command line options.
     */
-    for (ax=1; ax<ac; ax++) {
-	arg = av[ax];
+    for (ax=1; ax<ac; ) {
+	arg = av[ax++];
+
+	if (ax >= ac)
+	    Usage();
+
 	if (strcmp(arg, "-display") == 0) {
-	    display_name = av[++ax];
+	    display_name = av[ax++];
 	}
 	else if (strcmp(arg, "-rc") == 0) {
-	    roachColor = av[++ax];
+	    roachColor = av[ax++];
 	}
 	else if (strcmp(arg, "-speed") == 0) {
-	    roachSpeed = atof(av[++ax]);
+	    roachSpeed = atof(av[ax++]);
 	}
 	else if (strcmp(arg, "-roaches") == 0) {
-	    maxRoaches = strtol(av[++ax], (char **)NULL, 0);
+	    maxRoaches = strtol(av[ax++], (char **)NULL, 0);
 	}
 	else {
 	    Usage();
@@ -212,6 +216,7 @@
     CoverRoot();
     
     XCloseDisplay(display);
+    return(0);
 }
 
 #define USEPRT(msg) fprintf(stderr, msg)
@@ -465,7 +470,7 @@
     Region covered;
     Region visible;
     Window *children;
-    int nChildren;
+    unsigned int nChildren;
     Window dummy;
     XWindowAttributes wa;
     int wx;
