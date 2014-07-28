--- prelude.h.orig	Fri Mar 31 19:13:52 1995
+++ prelude.h	Wed Jan 31 01:41:35 2001
@@ -28,7 +28,7 @@
 #define ZTC      0	/* For IBM PC (>= 386) Zortech C++ v3.0 (-mx)	   */
 #define DJGPP    0	/* For DJGPP version 1.09 (gcc2.2.2) and DOS 5.0   */
 #define OS2      0	/* For IBM OS/2 2.0 using EMX GCC		   */
-#define SUNOS    1      /* For Sun 3/Sun 4 running SunOs 4.x		   */
+#define SUNOS    0      /* For Sun 3/Sun 4 running SunOs 4.x		   */
 #define MIPS	 0	/* For MIPS RC6280/Sony machine NWS-3870	UN */
 #define NEXTSTEP 0      /* For NeXTstep 3.0 using NeXT cc		   */
 #define NEXTGCC  0	/* For NeXTstep with gcc 2.x, doesn't work w/ NS3.2*/
@@ -36,6 +36,7 @@
 #define AMIGA    0	/* For Amiga using gcc 2.2.2			UN */
 #define HPUX     0      /* For HPUX using gcc				   */
 #define LINUX    0      /* For Linux using gcc				UN */
+#define FREEBSD  1      /* For FreeBSD using gcc			UN */
 #define RISCOS   0	/* For Acorn DesktopC and RISCOS2 or 3		   */
 #define ALPHA	 0	/* For DEC Alpha with OSF/1 (32 bit ints, no gofc) */
 #define SVR4	 0	/* For SVR4 using GCC2.2			   */
@@ -82,7 +83,7 @@
 
 #define UNIX		(SUNOS  | NEXTSTEP | HPUX | NEXTGCC | LINUX | AMIGA | \
 			 MINIX68K | ALPHA | OS2 | SVR4 | ULTRIX | AIX | MIPS |\
-			 SGI4 | NETBSD)
+			 SGI4 | NETBSD | FREEBSD)
 #define SMALL_GOFER	(TURBOC | BCC)
 #define REGULAR_GOFER	(RISCOS | DJGPP | ZTC | ATARI)
 #define LARGE_GOFER	(UNIX   | WATCOM)
@@ -91,7 +92,7 @@
 #define TERMIO_IO	(LINUX  | HPUX | OS2 | SVR4 | SGI4)
 #define SGTTY_IO	(SUNOS  | NEXTSTEP | NEXTGCC | AMIGA | MINIX68K | \
 			 ALPHA  | ULTRIX | AIX | MIPS)
-#define TERMIOS_IO      (NETBSD)
+#define TERMIOS_IO      (NETBSD | FREEBSD)
 #define BREAK_FLOATS	(TURBOC | BCC)
 #define HAS_FLOATS	(REGULAR_GOFER | LARGE_GOFER | BREAK_FLOATS)
 
@@ -202,7 +203,7 @@
 #define	farCalloc(n,s)	(Void *)valloc(((unsigned)n)*((unsigned)s))
 #endif
 
-#if     (HPUX | DJGPP | ZTC | LINUX | ALPHA | OS2 | SVR4 | AIX | SGI4 | NETBSD)
+#if     (HPUX | DJGPP | ZTC | LINUX | ALPHA | OS2 | SVR4 | AIX | SGI4 | NETBSD | FREEBSD)
 #include <stdlib.h>
 #define  far
 #endif
