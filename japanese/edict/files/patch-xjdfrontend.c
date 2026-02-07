--- xjdfrontend.c	1998-09-16 02:28:03.000000000 +0200
+++ xjdfrontend.c	2007-12-28 19:54:07.000000000 +0100
@@ -55,6 +55,8 @@
 
 #ifdef __STRICT_BSD__
 static struct sgttyb    orig,new;
+#elif defined(__POSIX__)
+static struct termios   orig,new;
 #else
 static struct termio    orig,new;
 #endif
@@ -240,6 +242,11 @@
     ioctl(0, TIOCGETP, &orig); ioctl(0, TIOCGETP, &new);
     new.sg_flags |= CBREAK; new.sg_flags &= ~ECHO;
     ioctl(0, TIOCSETP, &new);
+#elif defined(__POSIX__)
+    tcgetattr(0, &orig); tcgetattr(0, &new);
+    new.c_lflag &= ~ICANON; new.c_lflag &= ~ISIG; new.c_lflag &= ~ECHO;
+    new.c_lflag &= ~IXON; new.c_cc[VMIN] = 1;
+    new.c_cc[4] = 1; new.c_cc[5] = 0;   tcsetattr(0, TCSANOW, &new);
 #else
     ioctl(0, TCGETA, &orig); ioctl(0, TCGETA, &new);
     new.c_lflag &= ~ICANON; new.c_lflag &= ~ISIG; new.c_lflag &= ~ECHO;
@@ -255,6 +262,8 @@
 {
 #ifdef __STRICT_BSD__
    ioctl(0, TIOCSETP, &orig);
+#elif defined(__POSIX__)
+   tcsetattr(0, TCSANOW, &orig);
 #else
    ioctl(0, TCSETA, &orig);
 #endif
