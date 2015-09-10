--- include/unixconf.h.good	Wed Nov 22 23:42:39 2000
+++ include/unixconf.h	Wed Nov 22 23:43:42 2000
@@ -206,7 +206,7 @@
  * A stat system call is done on the mailbox every MAILCKFREQ moves.
  */
 
-#define MAIL			/* Deliver mail during the game */
+/* #define MAIL	*/		/* Deliver mail during the game */
 
 /* The Andrew Message System does mail a little differently from normal
  * UNIX.  Mail is deposited in the user's own directory in ~/Mailbox
