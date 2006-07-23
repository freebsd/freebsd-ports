--- cl_main.c.orig	Wed Jan  7 00:39:44 2004
+++ cl_main.c	Sun Jan 22 22:49:30 2006
@@ -44,6 +44,10 @@
 #include "mp3_player.h"
 
 #ifndef _WIN32
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
 #include <netdb.h>		
 #endif
 
@@ -850,19 +854,16 @@
 		Sys_Error ("Couldn't load gfx/colormap.lmp");
 	FMod_CheckModel("gfx/colormap.lmp", host_colormap, com_filesize); 
 
-	Sys_mkdir(va("%s/qw", com_basedir));
-	Sys_mkdir(va("%s/fuhquake", com_basedir));	
-
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
 
