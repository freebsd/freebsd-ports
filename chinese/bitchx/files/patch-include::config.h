--- include/config.h~	Sun Mar 25 02:28:49 2001
+++ include/config.h	Sun Mar 25 02:30:53 2001
@@ -35,7 +35,7 @@
  * too peruse this function all you like. It's not a BACKDOOR in any way, 
  * shape or form.
  */
-#define WANT_NOTIFY_BITCHX_COM ON
+#define WANT_NOTIFY_BITCHX_COM OFF
 
 
 /*
@@ -51,7 +51,36 @@
  * on any servers you add into this list. also the very last server should not 
  * have a continuation char.
  */
-#define DEFAULT_SERVER	"[ODNet] "\
+#define DEFAULT_SERVER	"[galaxynet] "\
+				"irc.taiwan.com "\
+				"Atlanta.GA.US.GalaxyNet.Org "\
+				"Boston.MA.US.GalaxyNet.Org "\
+				"Charlotte.NC.US.GalaxyNet.Org "\
+				"Exiled.US.GalaxyNet.Org "\
+				"Gymnet.US.GalaxyNet.Org "\
+				"Honolulu.HI.US.GalaxyNet.Org "\
+				"Imns.US.GalaxyNet.Org "\
+				"Intermedia.US.GalaxyNet.Org "\
+				"Sedona.AZ.US.GalaxyNet.Org "\
+				"K-Systems.SG.GalaxyNet.Org "\
+				"Lycos.SG.GalaxyNet.Org "\
+				"Pacific.SG.GalaxyNet.Org "\
+				"Singapore.SG.GalaxyNet.Org "\
+				"Singnet.SG.GalaxyNet.Org "\
+				"Swiftech.SG.GalaxyNet.Org "\
+				"Swiftech.SG.GalaxyNet.Org "\
+				"Caen.FR.GalaxyNet.Org "\
+				"Copenhagen.DK.GalaxyNet.Org "\
+				"Online.BE.GalaxyNet.Org "\
+				"Opaltelecom.UK.GalaxyNet.Org "\
+				"Oslo.NO.GalaxyNet.Org "\
+				"Vltmedia.SE.GalaxyNet.Org "\
+				"Xcal.UK.GalaxyNet.Org "\
+				"Zeelandnet.NL.GalaxyNet.Org "\
+				"Netvision.IL.GalaxyNet.Org "\
+				"Auckland.NZ.GalaxyNet.Org "\
+				"Chariot.AU.GalaxyNet.Org "\
+			"[ODNet] "\
 				"irc.bitchx.com "\
 			"[efnet] "\
 				"irc.total.net "\
@@ -245,6 +274,23 @@
  */
 #undef WANT_HEBREW
 
+#define WANT_BIG5
+
+/* XXX I hope this could be integrated into BX.
+ * XXX Well, this should be done via libc,
+ *     but FreeBSD libc support is quite LAME.
+ *     Macro below are copied from lynx.
+ *
+ *                            clive@FreeBSD.org
+ */
+#ifdef WANT_BIG5
+/* Encoding range below belongs to Big5+ */
+#define is_big5_los(lo) (((char)0x40<=lo)&&(lo<=(char)0x7E))        /* standard */
+#define is_big5_lox(lo) (((char)0x80<=lo)&&(lo<=(char)0xFE))        /* extended */
+#define is_big5_hi(hi)  (((char)0x81<=hi)&&(hi<=(char)0xFE))
+#define is_big5(hi,lo) is_big5_hi(hi) && (is_big5_los(lo) || is_big5_lox(lo))
+#endif WANT_BIG5
+
 /* if you use cidentd the filename is called .authlie instead of .noident.
  * as well some modifications to the format of the file were made. So we 
  * require some pre-knowledge of what to expect. WinNT identd servers will 
@@ -346,7 +392,7 @@
  * when you've defined LATIN1. The problem is that ansi graphics will look
  * ugly if you use the scroll up feature (PageUp/PageDown)
  */
-#undef ASCII_LOGO
+#define ASCII_LOGO
 
 /* If you define REVERSE_WHITE_BLACK, then the format codes for black and
  * white color are revepsed. (%W, %w is bold black and black, %K, %k is bold
@@ -379,7 +425,7 @@
 
 #define DEFAULT_PING_TYPE 1
 #define DEFAULT_MSGLOG ON
-#define DEFAULT_AUTO_NSLOOKUP OFF
+#define DEFAULT_AUTO_NSLOOKUP ON
 #define DEFAULT_ALT_CHARSET ON
 #define DEFAULT_FLOOD_KICK ON
 #define DEFAULT_FLOOD_PROTECTION ON
@@ -388,9 +434,9 @@
 #define DEFAULT_LLOOK_DELAY 120
 #define DEFAULT_ALWAYS_SPLIT_BIGGEST ON
 #define DEFAULT_AUTO_UNMARK_AWAY OFF
-#define DEFAULT_AUTO_WHOWAS OFF
+#define DEFAULT_AUTO_WHOWAS ON
 #define DEFAULT_BANTIME 600
-#define DEFAULT_BEEP ON
+#define DEFAULT_BEEP OFF
 #define DEFAULT_BEEP_MAX 3
 #define DEFAULT_BEEP_WHEN_AWAY OFF
 #define DEFAULT_BOLD_VIDEO ON
@@ -474,7 +520,7 @@
 #define DEFAULT_NOTIFY ON
 #define DEFAULT_QUEUE_SENDS 0
 #define DEFAULT_MAX_SERVER_RECONNECT 2
-#define DEFAULT_SERVER_GROUPS OFF
+#define DEFAULT_SERVER_GROUPS ON
 #define DEFAULT_WINDOW_DESTROY_PART OFF
 #define DEFAULT_WINDOW_DESTROY_QUERY OFF
 #define DEFAULT_SUPPRESS_SERVER_MOTD ON
@@ -593,9 +639,9 @@
 #endif 
 /* _USE_LOCAL_CONFIG */
 
-#define DEFAULT_KICK_REASON "Bitch-X BaBy!"
+#define DEFAULT_KICK_REASON "Bye loser!"
 #define DEFAULT_PROTECT_CHANNELS "*"
-#define DEFAULT_SHITLIST_REASON "Surplus Lamerz must go!!!!"
+#define DEFAULT_SHITLIST_REASON "Stupid people must die."
 #define DEFAULT_BEEP_ON_MSG "MSGS"
 #define DEFAULT_CMDCHARS "/"
 #define DEFAULT_CONTINUED_LINE "          "
@@ -606,7 +652,7 @@
 #define DEFAULT_SHELL "/bin/sh"
 #define DEFAULT_SHELL_FLAGS "-c"
 #define DEFAULT_USERINFO ""
-#define DEFAULT_XTERM "rxvt"
+#define DEFAULT_XTERM "xterm-color"
 #define DEFAULT_XTERM_OPTIONS "-bg black -fg white"
 #define DEFAULT_DCC_DLDIR "~"
 
