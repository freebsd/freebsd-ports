--- code/qcommon/q_shared.h.orig	2008-11-03 17:03:54 UTC
+++ code/qcommon/q_shared.h
@@ -27,11 +27,12 @@ Foundation, Inc., 51 Franklin St, Fifth 
 // A user mod should never modify this file
 
 #ifdef STANDALONE
-  #define PRODUCT_NAME			"iofoo3"
-  #define BASEGAME			"foobar"
-  #define CLIENT_WINDOW_TITLE     	"changeme"
-  #define CLIENT_WINDOW_MIN_TITLE 	"changeme2"
-  #define GAMENAME_FOR_MASTER		"iofoo3"	// must NOT contain whitespaces
+  #define PRODUCT_NAME			"ioq3+UT"
+  #define BASEGAME			"q3ut4"
+  #define CLIENT_WINDOW_TITLE     	"ioUrbanTerror"
+  #define CLIENT_WINDOW_MIN_TITLE 	"ioUT"
+  #define GAMENAME_FOR_MASTER		"Quake3Arena"	// must NOT contain whitespace
+  #define LEGACY_PROTOCOL
 #else
   #define PRODUCT_NAME			"ioq3"
   #define BASEGAME			"baseq3"
