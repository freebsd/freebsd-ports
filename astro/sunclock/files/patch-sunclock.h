--- sunclock.h.orig	Sat Jul 21 11:49:41 2001
+++ sunclock.h	Sat Dec  8 21:28:41 2001
@@ -224,7 +224,7 @@
         unsigned char * daypixel;       /* pointer to day pixels */
         unsigned char * nightpixel;     /* pointer to night pixels */
         int             ncolors;        /* number of colors in day pixels */
-	long		time;		/* time - real or fake, see flags */
+	time_t		footime;		/* time - real or fake, see flags */
 	long		projtime;	/* last time projected illumination */
 	long		roottime;	/* last time written to root */
 	long		animtime;	/* last time of animation */
