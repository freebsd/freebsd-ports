--- include/config.h~	Tue Jan  9 11:43:18 2001
+++ include/config.h	Tue Jan  9 11:45:40 2001
@@ -52,7 +52,7 @@
  * have a continuation char.
  */
 #define DEFAULT_SERVER	"[ODNet] "\
-				"irc.bitchx.com "\
+				"irc.taiwan.com "\
 			"[efnet] "\
 				"irc.total.net "\
 				"ircd.c-com.net "\
@@ -239,6 +239,23 @@
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
+/* XXX I didn't check the encoding range of big5+. This is standard big5. */
+#define is_big5_los(lo) (((char)0x40<=lo)&&(lo<=(char)0x7E))        /* standard */
+#define is_big5_lox(lo) (((char)0x80<=lo)&&(lo<=(char)0xFE))        /* extended */
+#define is_big5_hi(hi)  (((char)0x81<=hi)&&(hi<=(char)0xFE))
+#define is_big5(hi,lo) is_big5_hi(hi) && (is_big5_los(lo) || is_big5_lox(lo))
+#endif WANT_BIG5
+
 /* if you use cidentd the filename is called .authlie instead of .noident.
  * as well some modifications to the format of the file were made. So we 
  * require some pre-knowledge of what to expect. WinNT identd servers will 
@@ -340,7 +357,7 @@
  * when you've defined LATIN1. The problem is that ansi graphics will look
  * ugly if you use the scroll up feature (PageUp/PageDown)
  */
-#undef ASCII_LOGO
+#define ASCII_LOGO
 
 /* If you define REVERSE_WHITE_BLACK, then the format codes for black and
  * white color are revepsed. (%W, %w is bold black and black, %K, %k is bold
