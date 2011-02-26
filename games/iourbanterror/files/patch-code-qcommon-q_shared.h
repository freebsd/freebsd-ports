--- code/qcommon/q_shared.h.orig	2011-02-09 01:42:54.000000000 +0100
+++ code/qcommon/q_shared.h	2011-02-19 01:11:38.000000000 +0100
@@ -27,11 +27,11 @@
 // A user mod should never modify this file
 
 #ifdef STANDALONE
-  #define PRODUCT_NAME			"iofoo3"
-  #define BASEGAME			"foobar"
-  #define CLIENT_WINDOW_TITLE     	"changeme"
-  #define CLIENT_WINDOW_MIN_TITLE 	"changeme2"
-  #define GAMENAME_FOR_MASTER		"iofoo3"		// must NOT contain whitespaces
+  #define PRODUCT_NAME			"ioq3+UT"
+  #define BASEGAME			"q3ut4"
+  #define CLIENT_WINDOW_TITLE     	"ioUrbanTerror"
+  #define CLIENT_WINDOW_MIN_TITLE 	"ioUT"
+  #define GAMENAME_FOR_MASTER		"Quake3Arena"		// must NOT contain whitespaces
   #define HEARTBEAT_FOR_MASTER		GAMENAME_FOR_MASTER
   #define FLATLINE_FOR_MASTER		GAMENAME_FOR_MASTER "dead"
 #else
