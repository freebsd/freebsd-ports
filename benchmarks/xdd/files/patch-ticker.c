--- ticker.c.orig	Fri Mar 16 07:12:27 2007
+++ ticker.c	Fri Mar 16 07:12:55 2007
@@ -75,7 +75,7 @@
     return;
 }
 /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
-#elif (LINUX || SOLARIS || AIX || HPUX || OSX)
+#elif (LINUX || SOLARIS || AIX || HPUX || OSX || FreeBSD)
 void
 ticker_open(tick_t *tickp) {
     uint32_t picos;
@@ -160,7 +160,7 @@
     return; /* Ticker not open, or error reading ticker */
 }
 /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
-#elif (LINUX || SOLARIS || AIX || HPUX || OSX)
+#elif (LINUX || SOLARIS || AIX || HPUX || OSX || FreeBSD)
 void
 ticker_read(tick_t *tickp) {
     struct timeval current_time;
@@ -197,7 +197,7 @@
  *
  * Close the ticker.
  */
-#if (WIN32 || LINUX || SOLARIS || AIX || HPUX || OSX)
+#if (WIN32 || LINUX || SOLARIS || AIX || HPUX || OSX || FreeBSD)
 void
 ticker_close(void) {
     ticker_period = 0;
