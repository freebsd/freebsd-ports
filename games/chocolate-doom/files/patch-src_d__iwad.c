--- src/d_iwad.c.orig	2015-09-26 11:05:54 UTC
+++ src/d_iwad.c
@@ -632,7 +632,7 @@ static void AddXdgDirs(void)
     // The "standard" location for IWADs on Unix that is supported by most
     // source ports is /usr/share/games/doom - we support this through the
     // XDG_DATA_DIRS mechanism, through which it can be overridden.
-    AddIWADPath(env, "/games/doom");
+    AddIWADPath(env, "/doom");
 }
 
 //
