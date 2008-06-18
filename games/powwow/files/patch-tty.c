Index: tty.c
@@ -33,7 +33,9 @@
 #include "tty.h"
 #include "tcp.h"
 
-#ifndef USE_SGTTY
+#ifdef POSIX
+#    include <termios.h>
+#elif !defined(USE_SGTTY)
 #  ifdef APOLLO
 #    include "/sys5.3/usr/include/sys/termio.h"
 #  else
@@ -64,6 +66,9 @@
 #  define O_CBREAK CBREAK
 #endif
 
+#ifdef POSIX
+typedef struct termios termiostruct;
+#else
 #if defined(TCSETS) || defined(TCSETATTR)
 #  ifndef TCSETS		/* cc for HP-UX  SHOULD define this... */
 #    define TCSETS TCSETATTR
@@ -75,6 +80,7 @@
 #  define TCGETS TCGETA
 typedef struct termio termiostruct;
 #endif
+#endif /* POSIX */
 
 #ifdef VSUSP
 #  define O_SUSP VSUSP
@@ -181,14 +187,22 @@
     ioctl(tty_read_fd, TIOCSLTC, &ltc);
 #else /* not USE_SGTTY */
     termiostruct ttyb;
+#if POSIX
+	tcgetattr(tty_read_fd, &ttyb);
+#else
     ioctl(tty_read_fd, TCGETS, &ttyb);
+#endif
     ttybsave = ttyb;
     ttyb.c_lflag &= ~(ECHO|ICANON);
     ttyb.c_cc[VTIME] = 0;
     ttyb.c_cc[VMIN] = 1;
     /* disable the special handling of the suspend key (handle it ourselves) */
     ttyb.c_cc[O_SUSP] = 0;
+#if POSIX
+	tcsetattr(tty_read_fd, TCSANOW, &ttyb);
+#else
     ioctl(tty_read_fd, TCSETS, &ttyb);
+#endif
 #endif /* USE_SGTTY */
 
 #ifdef USE_LOCALE
@@ -216,7 +230,11 @@
     ioctl(tty_read_fd, TIOCSETC, &tcsave);
     ioctl(tty_read_fd, TIOCSLTC, &ltcsave);
 #else /* not USE_SGTTY */
+#if POSIX
+	tcsetattr(tty_read_fd, TCSANOW, &ttybsave);
+#else
     ioctl(tty_read_fd, TCSETS, &ttybsave);
+#endif
 #endif /* USE_SGTTY */
     tty_puts(kpadend);
     tty_flush();
@@ -251,7 +269,11 @@
 #else /* not USE_SGTTY */
     int i;
     termiostruct ttyb;
+#if POSIX
+	tcgetattr(tty_read_fd, &ttyb);
+#else
     ioctl(tty_read_fd, TCGETS, &ttyb);
+#endif
     if (linemode & LM_CHAR)  {
 	/* char-by-char mode: disable all special keys and set raw mode */
 	for(i = 0; i < NCCS; i++)
@@ -266,7 +288,11 @@
 	/* set cooked mode */
 	ttyb.c_oflag |= OPOST;
     }
+#if POSIX
+	tcsetattr(tty_read_fd, TCSANOW, &ttyb);
+#else
     ioctl(tty_read_fd, TCSETS, &ttyb);
+#endif
 #endif /* USE_SGTTY */
 }
