--- mbo.h.orig	2003-08-28 03:36:01.000000000 +0200
+++ mbo.h	2008-06-20 22:15:46.000000000 +0200
@@ -6,6 +6,7 @@
 #endif
 
 int mbo_init(char *device);
+char *mbo_artistname (void);
 char *mbo_trackname (int i);
 
 #define CDI_HOME ".cdindex" 	/* for historical reasons */
