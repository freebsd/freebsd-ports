--- hack/hack.tty.c	Wed Jun 23 21:36:26 2004
+++ hack/hack.tty.c	Wed Jun 23 21:50:12 2004
@@ -95,8 +95,8 @@
 #define CBRKMASK	CBREAK
 #define CBRKON		/* empty */
 #define OSPEED(x)	(x).sg_ospeed
-#define GTTY(x)		(gtty(0, x))
-#define STTY(x)		(stty(0, x))
+#define GTTY(x)		(ioctl(0, TIOCGETP, x))
+#define STTY(x)		(ioctl(0, TIOCSETP, x))
 
 #endif /* USG */
 
