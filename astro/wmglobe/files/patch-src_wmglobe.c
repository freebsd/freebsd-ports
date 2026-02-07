--- src/wmglobe.c.orig	2001-08-12 15:41:22 UTC
+++ src/wmglobe.c
@@ -35,7 +35,17 @@
 #include "defnimap.xpm"
 #endif
 
+/*
+ * variables globales
+ */
 
+Display *dpy;
+Pixmap pix, pixmask;
+XEvent Event;
+RImage *map, *small, *mapnight;
+Window iconwin, win;
+GC NormalGC;
+double marker[MAX_MARKERS][3];
 
 
 
@@ -414,7 +424,7 @@ int main(int argc, char *argv[])
 	    if (do_something) {
 		if (!myRConvertImage(ctx, small, &pix)) {
 		    fprintf(stderr, "crash !?\n");
-		    fprintf(stderr, RMessageForError(RErrorCode));
+		    fprintf(stderr, "%s", RMessageForError(RErrorCode));
 		    exit(1);
 		}
 		wmg.pixmap = pix;
