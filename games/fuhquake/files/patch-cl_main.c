--- cl_main.c.orig	Wed May 21 17:18:35 2003
+++ cl_main.c	Sun May 25 20:30:58 2003
@@ -43,6 +43,10 @@
 #include "mp3_player.h"
 
 #ifndef _WIN32
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
 #include <netdb.h>		
 #endif
 
@@ -857,13 +861,13 @@
 	Key_Init ();
 	V_Init ();
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 	IN_Init ();
 #endif
 
 	VID_Init (host_basepal);
 
-#ifndef __linux__
+#if !(defined(__linux__) || defined(__FreeBSD__))
 	IN_Init ();
 #endif
 
