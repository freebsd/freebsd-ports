--- src/s/freebsd.h.orig	Tue Aug 21 00:58:16 2007
+++ src/s/freebsd.h	Sun Sep 23 09:48:05 2007
@@ -181,7 +181,9 @@
    compiler seems to be modified to not find headers in
    /usr/local/include or libs in /usr/local/lib by default.  */
 
+#ifndef HAVE_CONFIG_H
 #define C_SWITCH_SYSTEM -I/usr/X11R6/include -I/usr/local/include -L/usr/local/lib
+#endif
 
 /* Circumvent a bug in FreeBSD.  In the following sequence of
    writes/reads on a PTY, read(2) returns bogus data:
