--- config.h.orig	1997-07-17 16:27:58 UTC
+++ config.h
@@ -30,7 +30,7 @@
 	    variable in the installed version, but you know best...
 */
 #ifndef ROOTDIR
-#define ROOTDIR "."
+#define ROOTDIR "%%PREFIX%%/lib/X11/xsokoban"
 #endif
 
 /*
@@ -46,7 +46,7 @@
                         the name <username>.sav
 */
 #ifndef SAVEPATH
-#define SAVEPATH ROOTDIR "/saves"
+#define SAVEPATH "/var/games/xsokoban/saves"
 #endif
 
 /*
@@ -62,14 +62,14 @@
              in the same directory as the score file.
 */
 #ifndef LOCKFILE
-#define LOCKFILE ROOTDIR "/scores/lock"
+#define LOCKFILE "/var/games/xsokoban/scores/lock"
 #endif
 
 /*
    SCOREFILE: the full pathname of the score file
 */
 #ifndef SCOREFILE
-#define SCOREFILE ROOTDIR "/scores/scores"
+#define SCOREFILE "/var/games/xsokoban/scores/scores"
 #endif
 
 /*
@@ -95,7 +95,7 @@
    OWNER: defines the name of the local game owner.
 */
 #ifndef OWNER
-#define OWNER "andru"
+#define OWNER "root"
 #endif
 
 /*
@@ -147,7 +147,7 @@
 */
 
 #ifndef WWW
-#define WWW 1
+#define WWW 0
 #endif
 
 #define DEBUG_SERVER(x)
