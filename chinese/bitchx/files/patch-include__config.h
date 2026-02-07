--- include/config.h.bak	2015-01-29 06:24:13.523281651 -0800
+++ include/config.h	2015-01-29 06:33:51.148252017 -0800
@@ -63,6 +63,10 @@
 				"ircnet.eversible.com "\
 				"ircnet.blacklotus.net "\
 				"irc.ca.ircnet.net "\
+			"[ircnet tw]"\
+				"irc.seed.net.tw"\
+				"irc.tw.freebsd.org"\
+				"irc.csie.nctu.edu.tw"\
 			"[ircnet EU] "\
 				"irc.dotsrc.org "\
 				"irc.belwue.de "\
@@ -150,7 +154,7 @@
  * we define the default network type for server groups. Do not just
  * undefine this.
  */
- #define DEFAULT_NETWORK "efnet"
+ #define DEFAULT_NETWORK "ircnet"
 
 /*
  * Below are the IRCII variable defaults.  For boolean variables, use 1 for
@@ -297,7 +301,7 @@
  * when you've defined LATIN1. The problem is that ansi graphics will look
  * ugly if you use the scroll up feature (PageUp/PageDown)
  */
-#undef ASCII_LOGO
+#define ASCII_LOGO
 
 /* If you define REVERSE_WHITE_BLACK, then the format codes for black and
  * white color are revepsed. (%W, %w is bold black and black, %K, %k is bold
@@ -330,7 +334,7 @@
 
 #define DEFAULT_PING_TYPE 1
 #define DEFAULT_MSGLOG ON
-#define DEFAULT_AUTO_NSLOOKUP OFF
+#define DEFAULT_AUTO_NSLOOKUP ON
 #define DEFAULT_ALT_CHARSET ON
 #define DEFAULT_FLOOD_KICK ON
 #define DEFAULT_FLOOD_PROTECTION ON
@@ -339,9 +343,9 @@
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
@@ -425,7 +429,7 @@
 #define DEFAULT_NOTIFY ON
 #define DEFAULT_QUEUE_SENDS 0
 #define DEFAULT_MAX_SERVER_RECONNECT 2
-#define DEFAULT_SERVER_GROUPS OFF
+#define DEFAULT_SERVER_GROUPS ON
 #define DEFAULT_WINDOW_DESTROY_PART OFF
 #define DEFAULT_WINDOW_DESTROY_QUERY OFF
 #define DEFAULT_SUPPRESS_SERVER_MOTD ON
@@ -558,7 +562,7 @@
 #define DEFAULT_SHELL "/bin/sh"
 #define DEFAULT_SHELL_FLAGS "-c"
 #define DEFAULT_USERINFO ""
-#define DEFAULT_XTERM "rxvt"
+#define DEFAULT_XTERM "xterm-color"
 #define DEFAULT_XTERM_OPTIONS "-bg black -fg white"
 #define DEFAULT_DCC_DLDIR "~"
 
@@ -692,6 +696,24 @@
 
 #define WANT_CORE
 
+#define WANT_BIG5
+
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
+#endif /*WANT_BIG5*/
+
 #undef OFF
 #undef ON
 
