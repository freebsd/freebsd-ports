--- term.c.orig	2009-10-06 23:10:29.000000000 +0800
+++ term.c	2009-10-06 23:20:40.000000000 +0800
@@ -10,16 +10,7 @@
 #include "bbs.h"
 #include <sys/ioctl.h>
 
-#ifdef HP_UX
-#define O_HUPCL 01
-#define O_XTABS 02
-#endif
-
-#ifdef LINUX
-#include <linux/termios.h>
-#define stty(fd, data) tcsetattr( fd, TCSETS, data )
-#define gtty(fd, data) tcgetattr( fd, data )
-#endif
+#define stty(fd, data) tcsetattr( fd, TCSANOW, data )
 
 #ifndef TANDEM
 #define TANDEM  0x00000001
@@ -29,11 +20,7 @@
 #define CBREAK  0x00000002
 #endif
 
-#ifdef LINUX
 struct termios tty_state, tty_new;
-#else
-struct sgttyb tty_state, tty_new;
-#endif
 
 
 /* ----------------------------------------------------- */
@@ -44,7 +31,7 @@
 void
 get_tty()
 {
-  if (gtty (1, &tty_state) < 0)
+  if (tcgetattr(1, &tty_state) < 0)
   {
      fprintf (stderr, "gtty failed\n");
      exit (-1);
@@ -53,46 +40,23 @@
 
 
 void
-init_tty()
+init_tty(void)
 {
-  if (gtty(1, &tty_state) < 0)
-  {
-    fprintf(stderr, "gtty failed\n");
-    exit(-1);
-  }
-  memcpy(&tty_new, &tty_state, sizeof(tty_new));
-
-#ifdef  LINUX
-
-  tty_new.c_lflag &= ~(ICANON | ECHO | RAW | ISIG);
-  tcsetattr(1, TCSANOW, &tty_new);
-  restore_tty();
-
-#else
-
-  tty_new.sg_flags |= RAW;
-
-#ifdef  HP_UX
-  tty_new.sg_flags &= ~(O_HUPCL | O_XTABS | LCASE | ECHO | CRMOD);
-#else
-  tty_new.sg_flags &= ~(TANDEM | CBREAK | LCASE | ECHO | CRMOD);
-#endif
+    struct termios tty_state, tty_new;
 
-  stty(1, &tty_new);
-#endif
+    if (tcgetattr(1, &tty_state) < 0) {
+	fprintf(stderr, "tcgetattr(): %m");
+        return;
+    }
+    memcpy(&tty_new, &tty_state, sizeof(tty_new));
+    tty_new.c_lflag &= ~(ICANON | ECHO | ISIG);
+    /*
+     * tty_new.c_cc[VTIME] = 0; tty_new.c_cc[VMIN] = 1;
+     */
+    tcsetattr(1, TCSANOW, &tty_new);
+    system("stty raw -echo");
 }
 
-
-#ifdef LINUX
-reset_tty()
-{
-   system("stty -raw echo");
-}
-restore_tty()
-{
-   system("stty raw -echo");
-}
-#else
 void
 reset_tty()
 {
@@ -104,7 +68,6 @@
   stty(1, &tty_new);
 }
 
-#endif
 
 
 
@@ -171,11 +134,7 @@
   char *sbp, *s;
   char *tgetstr();
 
-#ifdef LINUX
   ospeed = cfgetospeed(&tty_state);
-#else
-  ospeed = tty_state.sg_ospeed;
-#endif
 
   if (tgetent(buf, term) != 1)
     return NA;
