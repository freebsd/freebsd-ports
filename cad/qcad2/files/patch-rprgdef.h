--- rprgdef.h.orig	Fri Sep 20 19:26:57 2002
+++ rprgdef.h	Tue Nov 19 16:48:27 2002
@@ -23,12 +23,14 @@
 
 
 // Uncomment for Linux
+/*
 #define DEF_LINUX           // Are we running Linux?
 #define RUNNING_LINUX   true
 #define RUNNING_WINDOWS false
 #define RUNNING_SOLARIS false
 #define RUNNING_IRIX    false
 #define DATADIR         "/usr/share"
+*/
 
 
 #ifdef __FreeBSD__
@@ -38,6 +40,7 @@
 #define RUNNING_WINDOWS false
 #define RUNNING_SOLARIS false
 #define RUNNING_IRIX    false
+#define DATADIR		"%%PREFIX%%/share"
 #endif
 
 
