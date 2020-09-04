Do not hardcode data directory (available as DATADIR)

--- src/jnstub.c.orig	2020-09-03 06:19:21 UTC
+++ src/jnstub.c
@@ -699,7 +699,9 @@ ExtInit(void)
 
 #if defined(__linux) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 		addsearchpath("/usr/share/games/jfsw");
-		addsearchpath("/usr/local/share/games/jfsw");
+#if defined(DATADIR)
+		addsearchpath(DATADIR);
+#endif
 #elif defined(__APPLE__)
 		addsearchpath("/Library/Application Support/JFShadowWarrior");
 #endif
