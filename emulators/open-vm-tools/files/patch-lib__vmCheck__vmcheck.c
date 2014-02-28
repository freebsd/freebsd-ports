--- lib/vmCheck/vmcheck.c.orig	2013-09-23 08:51:10.000000000 -0700
+++ lib/vmCheck/vmcheck.c	2014-01-27 20:58:46.000000000 -0800
@@ -134,6 +134,7 @@
 #else
    do {
       int signals[] = {
+         SIGBUS,
          SIGILL,
          SIGSEGV,
       };
