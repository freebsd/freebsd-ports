--- src/fe-text/screen.h.orig	Fri Apr 27 19:13:01 2001
+++ src/fe-text/screen.h	Fri Apr 27 22:38:46 2001
@@ -16,6 +16,21 @@
 #define ATTR_COLOR8    0x200
 #define ATTR_REVERSE   0x400
 
+/* XXX I hope this could be integrated into BX.
+ * XXX Well, this should be done via libc,
+ *     but FreeBSD libc support is quite LAME.
+ *     Macro below are copied from lynx.
+ *
+ *				clive@FreeBSD.org
+ */
+#ifdef WANT_BIG5
+/* XXX I didn't check the encoding range of big5+. This is standard big5. */
+#define is_big5_los(lo) (((char)0x40<=lo)&&(lo<=(char)0x7E))	/* standard */
+#define is_big5_lox(lo) (((char)0x80<=lo)&&(lo<=(char)0xFE))	/* extended */
+#define is_big5_hi(hi)  (((char)0x81<=hi)&&(hi<=(char)0xFE))
+#define is_big5(hi,lo) is_big5_hi(hi) && (is_big5_los(lo) || is_big5_lox(lo))
+#endif WANT_BIG5
+
 int init_screen(void); /* Initialize screen, detect screen length */
 void deinit_screen(void); /* Deinitialize screen */
 
