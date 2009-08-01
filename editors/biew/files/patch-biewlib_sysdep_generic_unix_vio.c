--- biewlib/sysdep/generic/unix/vio.c.orig	2009-01-31 17:08:22.000000000 +0600
+++ biewlib/sysdep/generic/unix/vio.c	2009-03-18 04:11:42.000000000 +0600
@@ -206,10 +206,6 @@
 static char *vtmp;
 static int out_fd;
 static int _color[8] = {0,4,2,6,1,5,3,7};
-static char *screen_cp;
-static unsigned is_unicode=0;
-
-static void *nls_handle;
 
 static unsigned char frames_vt100[0x30] =
 "aaaxuuukkuxkjjjkmvwtqnttmlvwtqnvvwwmmllnnjlaaaaa";
@@ -242,6 +238,10 @@
 
 #endif	/* _VT100_ */
 
+static char *screen_cp;
+static unsigned is_unicode=0;
+static void *nls_handle;
+
 static unsigned char frames_dumb[0x30] =
 ": %|{+++++|+++++`++}-++++++++-+++++++++++++#%[]~";
 
