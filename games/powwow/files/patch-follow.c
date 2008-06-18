Index: follow.c
@@ -13,7 +13,9 @@
 #include <sys/time.h>
 #include <sys/types.h>
 
-#ifndef USE_SGTTY
+#ifdef POSIX
+#    include <termios.h>
+#elif !defined(USE_SGTTY)
 # ifdef APOLLO
 #  include "/sys5.3/usr/include/sys/termio.h"
 # else
@@ -44,6 +46,9 @@
 # define O_CBREAK CBREAK
 #endif
 
+#ifdef POSIX
+typedef struct termios termiostruct;
+#else
 #if defined(TCSETS) || defined(TCSETATTR)
 # ifndef TCSETS		/* cc for HP-UX  SHOULD define this... */
 #  define TCSETS TCSETATTR
@@ -55,6 +60,7 @@
 # define TCGETS TCGETA
 typedef struct termio termiostruct;
 #endif
+#endif /* POSIX */
 
 #ifdef VSUSP
 # define O_SUSP VSUSP
@@ -102,14 +108,22 @@
     ioctl(0, TIOCSLTC, &ltc);
 #else /* not USE_SGTTY */
     termiostruct ttyb;
+#if POSIX
+	tcgetattr(0, &ttyb);
+#else
     ioctl(0, TCGETS, &ttyb);
+#endif
     ttybsave = ttyb;
     ttyb.c_lflag &= ~(ECHO|ICANON);
     ttyb.c_cc[VTIME] = 0;
     ttyb.c_cc[VMIN] = 1;
     /* disable the special handling of the suspend key (handle it ourselves) */
     ttyb.c_cc[O_SUSP] = 0;
+#if POSIX
+	tcsetattr(0, TCSANOW, &ttyb);
+#else
     ioctl(0, TCSETS, &ttyb);
+#endif
 #endif /* USE_SGTTY */
 }
 
@@ -123,7 +137,11 @@
     ioctl(0, TIOCSETC, &tcsave);
     ioctl(0, TIOCSLTC, &ltcsave);
 #else /* not USE_SGTTY */
+#if POSIX
+	tcsetattr(0, TCSANOW, &ttybsave);
+#else
     ioctl(0, TCSETS, &ttybsave);
+#endif
 #endif /* USE_SGTTY */
 }
 
