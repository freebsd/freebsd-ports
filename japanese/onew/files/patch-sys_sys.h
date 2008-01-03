--- sys/sys.h	1995-06-30 06:56:38.000000000 +0200
+++ sys/sys.h	2007-12-28 14:24:01.000000000 +0100
@@ -29,12 +29,16 @@
  || defined(sony_news) \
  || defined(MACH) \
  || defined(NeXT) \
- || defined(bsdi) \
- || defined(__FreeBSD__)
+ || defined(bsdi)
 #define USE_SGTTY
 #define HAS_SELECT
 #endif
 
+#if defined(__FreeBSD__)
+#define USE_TERMIOS
+#define HAS_SELECT
+#endif
+
 #if defined(solaris) \
  || defined(sgi) \
  || defined(nec_ews) \
--- sys/tty.c	1994-02-09 08:45:24.000000000 +0100
+++ sys/tty.c	2007-12-28 14:31:11.000000000 +0100
@@ -76,8 +76,10 @@
 	if( on )
 		buf.c_lflag |= (ECHO|ICANON);
 	else	buf.c_lflag &= ~(ECHO|ICANON);
+	buf.c_cc[VMIN]  = 0;
+	buf.c_cc[VTIME] = ('D'-0x40);
+	buf.c_lflag |=  ICANON;
 	tcsetattr(fd, TCSADRAIN, &buf);
-	set_cbreak(fd,!on);
 	close(fd);
 }
 #endif
