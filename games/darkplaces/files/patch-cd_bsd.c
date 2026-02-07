--- cd_bsd.c.orig	2011-10-23 01:01:02.000000000 +0400
+++ cd_bsd.c	2011-10-23 01:02:00.000000000 +0400
@@ -39,7 +39,7 @@
 #ifndef __FreeBSD__
 # define DEFAULT_CD_DEVICE _PATH_DEV "cd0"
 #else
-# define DEFAULT_CD_DEVICE "/dev/acd0c"
+# define DEFAULT_CD_DEVICE "/dev/acd0"
 #endif
 
 static int cdfile = -1;
