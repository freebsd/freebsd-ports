diff -ruN ./include/unixconf.h ../nethack-3.2.2/include/unixconf.h
--- ./include/unixconf.h	Wed Dec 11 05:20:08 1996
+++ ../nethack-3.2.2/include/unixconf.h	Sun Mar 21 17:25:02 1999
@@ -31,7 +31,7 @@
 
 /* define any of the following that are appropriate */
 /* #define SVR4		/* use in addition to SYSV for System V Release 4 */
-#define NETWORK		/* if running on a networked system */
+/* #define NETWORK		/* if running on a networked system */
 			/* e.g. Suns sharing a playground through NFS */
 #define SUNOS4	/* SunOS 4.x */
 /* #define LINUX	/* Another Unix clone */
@@ -42,12 +42,12 @@
 /* #define AIX_31	/* In AIX 3.1 (IBM RS/6000) use BSD ioctl's to gain
 			 * job control (note that AIX is SYSV otherwise)
 			 * Also define this for AIX 3.2 */
-/* #define TEXTCOLOR	/* Use System V r3.2 terminfo color support */
+#define TEXTCOLOR	/* Use System V r3.2 terminfo color support */
 			/* and/or ANSI color support on termcap systems */
 			/* and/or X11 color */
-/* #define POSIX_JOB_CONTROL	/* use System V / POSIX job control
+#define POSIX_JOB_CONTROL	/* use System V / POSIX job control
 			 * (e.g., VSUSP) */
-/* #define POSIX_TYPES	/* use POSIX types for system calls and termios */
+#define POSIX_TYPES	/* use POSIX types for system calls and termios */
 			/* define for many recent OS releases, including
 			 * those with specific defines (since types are
 			 * changing toward the standard from earlier chaos).
@@ -125,7 +125,7 @@
  * A stat system call is done on the mailbox every MAILCKFREQ moves.
  */
 
-#define MAIL			/* Deliver mail during the game */
+/* #define MAIL			/* Deliver mail during the game */
 
 /* The Andrew Message System does mail a little differently from normal
  * UNIX.  Mail is deposited in the user's own directory in ~/Mailbox
