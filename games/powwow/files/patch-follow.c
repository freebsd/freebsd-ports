--- follow.c.orig	2002-02-19 19:42:34.000000000 +0000
+++ follow.c
@@ -96,7 +96,7 @@ void set_terminal()
     ioctl(0, TIOCGLTC, &ltcsave);
     ttyb = ttybsave;
     ttyb.sg_flags = (ttyb.sg_flags|O_CBREAK) & ~O_ECHO;
-    ioctl(tty_read_fd, TIOCSETP, &ttyb);
+    ioctl(0, TIOCSETP, &ttyb);
     ltc = ltcsave;
     ltc.t_suspc = -1;
     ioctl(0, TIOCSLTC, &ltc);
