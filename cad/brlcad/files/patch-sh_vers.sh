--- sh/vers.sh.orig	Fri Dec 17 22:01:05 2004
+++ sh/vers.sh	Sun Feb 13 13:50:59 2005
@@ -85,7 +85,7 @@
 awk '{version = $1 + 1; };END{printf "%d\n", version > "version"; }' < version
 
 VERSION=`cat version`
-DATE=`date`
+DATE=`LC_ALL=C date`
 PATH=$PATH:/usr/ucb:/usr/bsd
 export PATH
 
