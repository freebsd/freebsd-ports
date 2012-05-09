--- include/vt.h.orig	1997-01-24 16:08:13.000000000 +0900
+++ include/vt.h	2012-05-10 00:14:28.784553183 +0900
@@ -60,6 +60,9 @@
 	active,
 	wrap,
 	text_mode;
+#if defined(__FreeBSD__)
+    bool cursor_key_mode;
+#endif	/* __FreeBSD__ */
 };
 
 extern struct	_con_info con;
@@ -75,6 +78,9 @@
 extern void	VtStart(void);
 extern void	VtEmu(const char*, int nchars);
 extern void	VtCleanup(void);
+#if defined(__FreeBSD__)
+extern int      cons25tovt100(u_char *buff, int len, const int max);
+#endif
 
 #define	sjistojis(ch, cl)\
 {\
