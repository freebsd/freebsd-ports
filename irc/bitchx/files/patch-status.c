--- source/status.c.orig	Fri Jul 18 04:58:48 2003
+++ source/status.c	Fri Jul 18 05:02:50 2003
@@ -1213,7 +1213,7 @@
  * current-type window, although i think they should go to all windows.
  */
 #define STATUS_VAR(x) \
-static	char	*status_user ## x ## (Window *window)			\
+static	char	*status_user ## x (Window *window)			\
 {									\
 	char	*text;							\
 									\
