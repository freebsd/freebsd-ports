Index: nss_resinit.c
diff -u -p nss_resinit.c.orig nss_resinit.c
--- nss_resinit.c.orig	Wed Apr 12 20:29:35 2006
+++ nss_resinit.c	Tue Jan 23 09:48:22 2007
@@ -44,6 +44,17 @@ __RCSID("$Mahoroba: src/nss_resinit/nss_
 
 #ifndef res_ninit
 typedef struct __res_state *res_state;
+#endif
+
+#ifdef WITH_COMPAT5X
+extern struct __res_state *___res(void);
+#undef	_res
+#define	_res		(*___res())
+#undef	res_ninit
+#undef	__res_vinit
+#endif
+
+#ifndef res_ninit
 #define	res_ninit(res)			res_init()
 #define	__res_vinit(res, preinit)	(res_close(), res_init())
 #endif
