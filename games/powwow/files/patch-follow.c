--- follow.c.orig	Wed Feb 13 15:59:06 2002
+++ follow.c	Wed Feb 13 15:59:46 2002
@@ -96,7 +96,7 @@
     ioctl(0, TIOCGLTC, &ltcsave);
     ttyb = ttybsave;
     ttyb.sg_flags = (ttyb.sg_flags|O_CBREAK) & ~O_ECHO;
-    ioctl(tty_read_fd, TIOCSETP, &ttyb);
+    ioctl(0, TIOCSETP, &ttyb);
     ltc = ltcsave;
     ltc.t_suspc = -1;
     ioctl(0, TIOCSLTC, &ltc);
@@ -127,7 +127,7 @@
 #endif /* USE_SGTTY */
 }
 
-void main(int argc, char *argv[]) {
+int main(int argc, char *argv[]) {
    FILE *f;
    char c = 0, buf[512];
    int d;
