--- plugins/r/src/tm_r.c.orig	Sat Dec  3 03:08:07 2005
+++ plugins/r/src/tm_r.c	Tue Dec  6 01:00:12 2005
@@ -10,8 +10,13 @@
 ******************************************************************************/
 
 #include <stdio.h>
+#include <sys/types.h>
 #include <sys/select.h>
+#ifdef __FreeBSD__
+#include <libutil.h>
+#else
 #include <pty.h>
+#endif
 #include <utmp.h>
 #include <unistd.h>
 #include <termios.h>
@@ -20,7 +25,6 @@
 #include <string.h>
 
 
-#include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <sys/time.h>
@@ -458,7 +462,11 @@
 #endif
 
       /* Main pselect switch --------------- */
+#if defined(__FreeBSD__) && __FreeBSD__ < 5
+      if( select( master+1, &rd, &wr, &er, NULL ) > 0 ) {
+#else
       if( pselect( master+1, &rd, &wr, &er, NULL, &orig_sigmask ) > 0 ) {
+#endif
 	if( FD_ISSET( STDIN_FILENO, &rd ) ) {
 	  /* =============== read input from TeXmacs */
 	  nread = read_B( STDIN_FILENO, RB, 1000 ) ;
