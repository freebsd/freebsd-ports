--- include/config.h.orig2	2012-11-05 22:31:31.000000000 -0500
+++ include/config.h	2012-11-05 22:31:12.000000000 -0500
@@ -99,7 +99,11 @@
 				"pinky.slashnet.org "\
 				"blago.slashnet.org "\
 				"moo.slashnet.org "\
-				"coruscant.slashnet.org "
+				"coruscant.slashnet.org "\
+			"[ircnet] "\
+				"irc.seed.net.tw "\
+				"irc.tw.freebsd.org "\
+				"irc.csie.nctu.edu.tw "
 #endif
 
 /*
@@ -152,7 +156,7 @@
  * we define the default network type for server groups. Do not just
  * undefine this.
  */
- #define DEFAULT_NETWORK "efnet"
+ #define DEFAULT_NETWORK "ircnet"
 
 /*
  * Below are the IRCII variable defaults.  For boolean variables, use 1 for
@@ -299,7 +303,7 @@
  * when you've defined LATIN1. The problem is that ansi graphics will look
  * ugly if you use the scroll up feature (PageUp/PageDown)
  */
-#undef ASCII_LOGO
+#define ASCII_LOGO
 
 /* If you define REVERSE_WHITE_BLACK, then the format codes for black and
  * white color are revepsed. (%W, %w is bold black and black, %K, %k is bold
@@ -332,7 +336,7 @@
 
 #define DEFAULT_PING_TYPE 1
 #define DEFAULT_MSGLOG ON
-#define DEFAULT_AUTO_NSLOOKUP OFF
+#define DEFAULT_AUTO_NSLOOKUP ON
 #define DEFAULT_ALT_CHARSET ON
 #define DEFAULT_FLOOD_KICK ON
 #define DEFAULT_FLOOD_PROTECTION ON
@@ -341,9 +345,9 @@
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
@@ -427,7 +431,7 @@
 #define DEFAULT_NOTIFY ON
 #define DEFAULT_QUEUE_SENDS 0
 #define DEFAULT_MAX_SERVER_RECONNECT 2
-#define DEFAULT_SERVER_GROUPS OFF
+#define DEFAULT_SERVER_GROUPS ON
 #define DEFAULT_WINDOW_DESTROY_PART OFF
 #define DEFAULT_WINDOW_DESTROY_QUERY OFF
 #define DEFAULT_SUPPRESS_SERVER_MOTD ON
@@ -560,7 +564,7 @@
 #define DEFAULT_SHELL "/bin/sh"
 #define DEFAULT_SHELL_FLAGS "-c"
 #define DEFAULT_USERINFO ""
-#define DEFAULT_XTERM "rxvt"
+#define DEFAULT_XTERM "xterm-color"
 #define DEFAULT_XTERM_OPTIONS "-bg black -fg white"
 #define DEFAULT_DCC_DLDIR "~"
 
@@ -695,6 +699,24 @@
 
 #define WANT_CORE
 
+
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
+#endif /*WANT_BIG5*/
+
 #undef OFF
 #undef ON
 
