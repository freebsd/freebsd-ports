--- term.c.orig	2008-05-01 19:34:15.000000000 +0800
+++ term.c	2008-05-01 19:44:06.000000000 +0800
@@ -9,17 +9,16 @@
 
 #include "bbs.h"
 #include <sys/ioctl.h>
+#include <stdlib.h>
 
 #ifdef HP_UX
 #define O_HUPCL 01
 #define O_XTABS 02
 #endif
 
-#ifdef LINUX
-#include <linux/termios.h>
-#define stty(fd, data) tcsetattr( fd, TCSETS, data )
+#include <termios.h>
+#define stty(fd, data) tcsetattr( fd, TCSANOW, data )
 #define gtty(fd, data) tcgetattr( fd, data )
-#endif
 
 #ifndef TANDEM
 #define TANDEM  0x00000001
@@ -29,11 +28,7 @@
 #define CBREAK  0x00000002
 #endif
 
-#ifdef LINUX
 struct termios tty_state, tty_new;
-#else
-struct sgttyb tty_state, tty_new;
-#endif
 
 
 /* ----------------------------------------------------- */
@@ -62,37 +57,11 @@
   }
   memcpy(&tty_new, &tty_state, sizeof(tty_new));
 
-#ifdef  LINUX
-
-  tty_new.c_lflag &= ~(ICANON | ECHO | RAW | ISIG);
-  tcsetattr(1, TCSANOW, &tty_new);
+  tty_new.c_lflag &= ~(ICANON | ECHO | ISIG);
   restore_tty();
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
-
-  stty(1, &tty_new);
-#endif
 }
 
 
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
@@ -104,8 +73,6 @@
   stty(1, &tty_new);
 }
 
-#endif
-
 
 
 /* ----------------------------------------------------- */
@@ -171,11 +138,7 @@
   char *sbp, *s;
   char *tgetstr();
 
-#ifdef LINUX
   ospeed = cfgetospeed(&tty_state);
-#else
-  ospeed = tty_state.sg_ospeed;
-#endif
 
   if (tgetent(buf, term) != 1)
     return NA;
