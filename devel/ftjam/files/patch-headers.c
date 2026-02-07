--- headers.c.orig	2014-08-07 15:23:32.000000000 +0200
+++ headers.c	2014-08-07 15:23:38.000000000 +0200
@@ -53,7 +53,6 @@
 {
 	LIST	*hdrscan;
 	LIST	*hdrrule;
-	LIST	*hdrcache;
 	LOL	lol;
 
 	if( !( hdrscan = var_get( "HDRSCAN" ) ) || 
