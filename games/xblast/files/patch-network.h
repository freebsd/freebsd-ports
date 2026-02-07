--- network.h.orig	2006-02-10 15:07:42 UTC
+++ network.h
@@ -105,7 +105,7 @@ typedef enum
 #define TEAM_UNDEF 252
 
 /* team color assignment */
-const XBColor teamColors[NUM_XBTS];
+extern const XBColor teamColors[NUM_XBTS];
 
 /* results of game config receive/create */
 typedef enum
