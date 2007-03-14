--- follow.c.orig	Sat Oct 14 00:12:28 2006
+++ follow.c	Sat Oct 14 00:12:43 2006
@@ -96,7 +96,7 @@
     ioctl(0, TIOCGLTC, &ltcsave);
     ttyb = ttybsave;
     ttyb.sg_flags = (ttyb.sg_flags|O_CBREAK) & ~O_ECHO;
-    ioctl(tty_read_fd, TIOCSETP, &ttyb);
+    ioctl(0, TIOCSETP, &ttyb);
     ltc = ltcsave;
     ltc.t_suspc = -1;
     ioctl(0, TIOCSLTC, &ltc);
