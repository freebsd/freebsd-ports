--- sircd/src/srv_commands.c.orig	Fri Jun 15 16:10:36 2001
+++ sircd/src/srv_commands.c	Fri Jun 15 16:11:25 2001
@@ -11,6 +11,8 @@
 */
 
 #include <srv_include.h>
+#include <sys/types.h>
+#include <sys/stat.h>
 
 #ifdef WIN32
 	#pragma warning(disable : 4090)	// const
