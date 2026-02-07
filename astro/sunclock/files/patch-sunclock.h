--- sunclock.h.orig	2006-10-14 14:25:18 UTC
+++ sunclock.h
@@ -238,7 +238,7 @@ typedef struct Sundata {
         unsigned char * nightpixel;     /* pointer to night pixels */
         Pixel           *vmfpixels;     /* list of additional vmf pixels */
         int             ncolors;        /* number of colors in day pixels */
-	long		time;		/* time - real or fake, see flags */
+	time_t		footime;		/* time - real or fake, see flags */
 	long		projtime;	/* last time projected illumination */
 	long		roottime;	/* last time written to root */
 	long		animtime;	/* last time of animation */
