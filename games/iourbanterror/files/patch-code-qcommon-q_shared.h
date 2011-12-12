--- code/qcommon/q_shared.h.orig	2011-10-27 02:45:12.000000000 +0200
+++ code/qcommon/q_shared.h	2011-10-27 02:47:17.000000000 +0200
@@ -27,15 +27,15 @@
 // A user mod should never modify this file
 
 #ifdef STANDALONE
-  #define PRODUCT_NAME			"iofoo3"
-  #define BASEGAME			"foobar"
-  #define CLIENT_WINDOW_TITLE     	"changeme"
-  #define CLIENT_WINDOW_MIN_TITLE 	"changeme2"
+  #define PRODUCT_NAME			"ioq3+UT"
+  #define BASEGAME			"q3ut4"
+  #define CLIENT_WINDOW_TITLE     	"ioUrbanTerror"
+  #define CLIENT_WINDOW_MIN_TITLE 	"ioUT"
   #define HOMEPATH_NAME_UNIX		HOMEPATH
   #define HOMEPATH_NAME_WIN		"FooBar"
   #define HOMEPATH_NAME_MACOSX		HOMEPATH_NAME_WIN
-  #define GAMENAME_FOR_MASTER		"foobar"	// must NOT contain whitespace
-//  #define LEGACY_PROTOCOL	// You probably don't need this for your standalone game
+  #define GAMENAME_FOR_MASTER		"Quake3Arena"	// must NOT contain whitespace
+  #define LEGACY_PROTOCOL	// You probably don't need this for your standalone game
 #else
   #define PRODUCT_NAME			"ioq3"
   #define BASEGAME			"baseq3"
