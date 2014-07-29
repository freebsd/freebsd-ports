--- src/ebview.c.orig	Sun Apr 13 18:43:30 2003
+++ src/ebview.c	Fri May  2 20:31:01 2003
@@ -20,9 +20,16 @@
 #include <sys/wait.h>
 #include <sys/socket.h>
 #include <sys/un.h>
-#include <getopt.h>
 #include <pthread.h>
 
+#ifdef HAVE_CONFIG_H
+#include "../config.h"
+#endif
+
+#ifdef HAVE_GETOPT_LONG
+#include <getopt.h>
+#endif
+
 #include "defs.h"
 #include "global.h"
 
@@ -200,7 +207,7 @@
 	optind = 0;
 
 	while(1){
-#ifdef __FreeBSD__
+#ifndef HAVE_GETOPT_LONG
 		c = getopt(g_argc, g_argv, "sprig:");
 #else 
 		c = getopt_long(g_argc, g_argv, "sprig:",
@@ -364,7 +371,7 @@
 	/* The total length of the address includes the sun_family 
 	   element */
 
-#ifdef __FreeBSD__
+#ifndef HAVE_GETOPT_LONG
         addrLength = sizeof(address.sun_len) + sizeof(address.sun_family) + strlen(address.sun_path) + 1;
         address.sun_len = addrLength;
 #else
