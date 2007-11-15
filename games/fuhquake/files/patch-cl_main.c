--- cl_main.c.orig	2004-01-07 00:39:44.000000000 +0600
+++ cl_main.c	2007-11-15 00:01:57.000000000 +0600
@@ -44,6 +44,10 @@
 #include "mp3_player.h"
 
 #ifndef _WIN32
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
 #include <netdb.h>		
 #endif
 
@@ -380,7 +384,7 @@
 	Q_strncpyz(address, Cmd_Argv(1), sizeof(address));
 	if (s = strchr(address, ':'))
 		*s = 0;
-	if (((int) addr.s_addr = inet_addr(address)) == INADDR_NONE) {
+	if ((addr.s_addr = inet_addr(address)) == INADDR_NONE) {
 		//forward lookup
 		if (!(h = gethostbyname(address))) {
 			Com_Printf("Couldn't resolve %s\n", address);
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
 
