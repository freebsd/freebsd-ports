--- src/d_iwad.c.orig	2017-12-30 16:20:28.000000000 -0500
+++ src/d_iwad.c	2018-01-25 09:43:00.567417000 -0500
@@ -658,7 +658,7 @@
     // The "standard" location for IWADs on Unix that is supported by most
     // source ports is /usr/share/games/doom - we support this through the
     // XDG_DATA_DIRS mechanism, through which it can be overridden.
-    AddIWADPath(env, "/games/doom");
+    AddIWADPath(env, "/doom");
 
     // The convention set by RBDOOM-3-BFG is to install Doom 3: BFG
     // Edition into this directory, under which includes the Doom
