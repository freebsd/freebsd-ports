--- include/unixconf.h.orig	Mon Jul 17 11:03:51 2000
+++ include/unixconf.h	Fri Oct 13 10:06:57 2000
@@ -47,7 +47,7 @@
 			 * job control (note that AIX is SYSV otherwise)
 			 * Also define this for AIX 3.2 */
 
-#define TERMINFO	/* uses terminfo rather than termcap */
+/* #define TERMINFO */	/* uses terminfo rather than termcap */
 			/* Should be defined for most SYSV, SVR4 (including
 			 * Solaris 2+), HPUX, and Linux systems.  In
 			 * particular, it should NOT be defined for the UNIXPC
@@ -143,7 +143,7 @@
  * A stat system call is done on the mailbox every MAILCKFREQ moves.
  */
 
-#define MAIL			/* Deliver mail during the game */
+/* #define MAIL */			/* Deliver mail during the game */
 
 /* The Andrew Message System does mail a little differently from normal
  * UNIX.  Mail is deposited in the user's own directory in ~/Mailbox
