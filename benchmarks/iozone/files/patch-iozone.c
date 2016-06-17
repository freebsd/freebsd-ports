--- iozone.c.orig	2015-10-20 14:12:13 UTC
+++ iozone.c
@@ -360,6 +360,7 @@ typedef off_t off64_t;
 #ifndef SCO_Unixware_gcc
 #ifndef UWIN
 #ifndef __DragonFly__
+#ifndef __FreeBSD__
 typedef long long off64_t;
 #endif
 #endif
@@ -369,6 +370,7 @@ typedef long long off64_t;
 #endif
 #endif
 #endif
+#endif
 
 #ifdef __AIX__
 #include <fcntl.h>
@@ -23009,7 +23011,7 @@ char *shell;
 #ifdef _HPUX_SOURCE
 	strcpy(shell,"remsh");
 #else
-	strcpy(shell,"rsh");
+	strcpy(shell,"ssh");
 #endif
 	return;
 }	
