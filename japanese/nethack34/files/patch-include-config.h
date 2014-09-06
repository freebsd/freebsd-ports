--- include/config.h.orig	2014-08-28 15:09:32.000000000 +0900
+++ include/config.h	2014-08-28 15:10:15.000000000 +0900
@@ -219,7 +219,7 @@
  * otherwise it will be the current directory.
  */
 # ifndef HACKDIR
-#  define HACKDIR "/usr/games/lib/jnethackdir"
+#  define HACKDIR "%%HACKDIR%%"
 # endif
 
 /*
