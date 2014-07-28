--- config.h.orig	Sat Jan 25 17:41:05 1992
+++ config.h	Wed Nov  8 04:47:56 2000
@@ -1,7 +1,9 @@
 #ifndef _config_H_
 #define _config_H_
 
+#ifndef SCOREDIR
 #define SCOREDIR "/usr/local/lib"
+#endif
 #define SCOREFNAME "yahtzee.sco"	/* must allow .L extension */
 
 #define NUM_TOP_PLAYERS 10
