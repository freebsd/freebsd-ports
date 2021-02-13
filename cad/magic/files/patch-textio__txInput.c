--- textio/txInput.c.orig	2020-05-24 07:00:08 UTC
+++ textio/txInput.c
@@ -28,6 +28,7 @@ static char rcsid[] __attribute__ ((unused)) = "$Heade
 #include <unistd.h>
 #include <ctype.h>
 #include <dirent.h>
+#include <termios.h>
 
 
 #include "utils/magsgtty.h"
@@ -1205,14 +1206,14 @@ TxGetLine(dest, maxChars)
  * ----------------------------------------------------------------------------
  */
 
-#if defined(SYSV) || defined(CYGWIN)
+#if defined(SYSV) || defined(CYGWIN) || defined(__FreeBSD__)
 
 void
 txGetTermState(buf)
-    struct termio *buf;
+    struct termios *buf;
 
 {
-    ioctl( fileno( stdin ), TCGETA, buf);
+    ioctl( fileno( stdin ), TIOCGETA, buf);
 }
 
 #else
@@ -1245,14 +1246,14 @@ txGetTermState(buf)
 
 void
 txSetTermState(buf)
-#if defined(SYSV) || defined(CYGWIN)
-    struct termio *buf;
+#if defined(SYSV) || defined(CYGWIN) || defined(__FreeBSD__)
+    struct termios *buf;
 #else
     txTermState *buf;
 #endif /* SYSV */
 {
-#if defined(SYSV) || defined(CYGWIN)
-    ioctl( fileno(stdin), TCSETAF, buf );
+#if defined(SYSV) || defined(CYGWIN) || defined(__FreeBSD__)
+    ioctl( fileno(stdin), TIOCSETAF, buf );
 #else
     /* set the current terminal characteristics */
     (void) ioctl(fileno(stdin), TIOCSETN, (char *) &(buf->tx_i_sgtty) );
@@ -1280,13 +1281,13 @@ txSetTermState(buf)
 
 void
 txInitTermRec(buf)
-#if defined(SYSV) || defined(CYGWIN)
-    struct termio *buf;
+#if defined(SYSV) || defined(CYGWIN) || defined(__FreeBSD__)
+    struct termios *buf;
 #else
     txTermState *buf;
 #endif /* SYSV */
 {
-#if defined(SYSV) || defined(CYGWIN)
+#if defined(SYSV) || defined(CYGWIN) || defined(__FreeBSD__)
     buf->c_lflag = ISIG;    /* raw: no echo and no processing, allow signals */
     buf->c_cc[ VMIN ] = 1;
     buf->c_cc[ VTIME ] = 0;
@@ -1301,8 +1302,8 @@ txInitTermRec(buf)
 
 
 
-#if defined(SYSV) || defined(CYGWIN)
-struct termio closeTermState;
+#if defined(SYSV) || defined(CYGWIN) || defined(__FreeBSD__)
+struct termios closeTermState;
 #else
 static txTermState closeTermState;
 #endif /* SYSV */
@@ -1328,8 +1329,8 @@ static bool haveCloseState = FALSE;
 void
 txSaveTerm()
 {
-#if defined(SYSV) || defined(CYGWIN)
-    ioctl( fileno( stdin ), TCGETA, &closeTermState);
+#if defined(SYSV) || defined(CYGWIN) || defined(__FreeBSD__)
+    ioctl( fileno( stdin ), TIOCGETA, &closeTermState);
     txEraseChar = closeTermState.c_cc[VERASE];
     txKillChar =  closeTermState.c_cc[VKILL];
     TxEOFChar = closeTermState.c_cc[VEOF];
@@ -1369,8 +1370,8 @@ txSaveTerm()
 void
 TxSetTerminal()
 {
-#if defined(SYSV) || defined(CYGWIN)
-    struct termio buf;
+#if defined(SYSV) || defined(CYGWIN) || defined(__FreeBSD__)
+    struct termios buf;
 #else
     txTermState buf;
 #endif /* SYSV */
