$FreeBSD$

--- source/config.h	Thu Jul 21 19:47:13 1994
+++ source/config.h	Tue Aug  5 10:04:39 2003
@@ -14,7 +14,7 @@
 
 /* Person to bother if something goes wrong.  */
 /* Recompile files.c and misc2.c if this changes.  */
-#define WIZARD	"David Grabiner"
+#define WIZARD	"root"
 /* The wizard password and wizard uid are no longer used.  */
 
 
@@ -200,16 +200,16 @@
 
 /* This must be unix; change MORIA_LIB as appropriate.  */
 #define MORIA_SAV	"moria.save"
-#define MORIA_LIB(xxx)  "/home/math/grabiner/moria/files/xxx"
-#define MORIA_HOU	MORIA_LIB(hours)
-#define MORIA_MOR	MORIA_LIB(news)
-#define MORIA_TOP	MORIA_LIB(scores)
-#define MORIA_HELP	MORIA_LIB(roglcmds.hlp)
-#define MORIA_ORIG_HELP	MORIA_LIB(origcmds.hlp)
-#define MORIA_WIZ_HELP	MORIA_LIB(rwizcmds.hlp)
-#define MORIA_OWIZ_HELP	MORIA_LIB(owizcmds.hlp)
-#define MORIA_WELCOME	MORIA_LIB(welcome.hlp)
-#define MORIA_VER	MORIA_LIB(version.hlp)
+#define MORIA_LIB(xxx)  "%%PREFIX%%/share/moria/" xxx
+#define MORIA_HOU	MORIA_LIB("hours")
+#define MORIA_MOR	MORIA_LIB("news")
+#define MORIA_TOP	MORIA_LIB("scores")
+#define MORIA_HELP	MORIA_LIB("roglcmds.hlp")
+#define MORIA_ORIG_HELP	MORIA_LIB("origcmds.hlp")
+#define MORIA_WIZ_HELP	MORIA_LIB("rwizcmds.hlp")
+#define MORIA_OWIZ_HELP	MORIA_LIB("owizcmds.hlp")
+#define MORIA_WELCOME	MORIA_LIB("welcome.hlp")
+#define MORIA_VER	MORIA_LIB("version.hlp")
 
 #endif
 #endif
