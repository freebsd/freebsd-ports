Do not hardcode data directory (available as DATADIR)

--- src/jnstub.c.orig	2014-11-17 19:10:37.306944907 +0100
+++ src/jnstub.c	2014-11-17 19:12:27.694272007 +0100
@@ -699,7 +699,9 @@
 
 #if defined(__linux) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 		addsearchpath("/usr/share/games/jfsw");
-		addsearchpath("/usr/local/share/games/jfsw");
+#if defined(DATADIR)
+		addsearchpath(DATADIR);
+#endif
 #elif defined(__APPLE__)
 		addsearchpath("/Library/Application Support/JFShadowWarrior");
 #endif
