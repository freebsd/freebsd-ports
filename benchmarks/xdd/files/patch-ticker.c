--- ticker.c.orig	Mon May 29 04:23:53 2006
+++ ticker.c	Mon May 29 04:24:15 2006
@@ -76,7 +76,7 @@
     return;
 }
 /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
-#elif (LINUX || SOLARIS || AIX || HPUX || OSX)
+#elif (LINUX || SOLARIS || AIX || HPUX || OSX || FreeBSD)
 void
 ticker_open(tick_t *tickp) {
     uint32_t picos;
@@ -161,7 +161,7 @@
     return; /* Ticker not open, or error reading ticker */
 }
 /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
-#elif (LINUX || SOLARIS || AIX || HPUX || OSX)
+#elif (LINUX || SOLARIS || AIX || HPUX || OSX || FreeBSD)
 void
 ticker_read(tick_t *tickp) {
     struct timeval current_time;
@@ -198,7 +198,7 @@
  *
  * Close the ticker.
  */
-#if (WIN32 || LINUX || SOLARIS || AIX || HPUX || OSX)
+#if (WIN32 || LINUX || SOLARIS || AIX || HPUX || OSX || FreeBSD)
 void
 ticker_close(void) {
     ticker_period = 0;
