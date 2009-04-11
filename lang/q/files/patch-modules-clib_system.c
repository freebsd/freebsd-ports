--- modules/clib/system.c.orig	2009-04-11 11:45:49.000000000 +0200
+++ modules/clib/system.c	2009-04-11 11:49:40.000000000 +0200
@@ -1689,7 +1689,7 @@
      mkvoid,
 #endif
 #ifdef _POSIX_CPUTIME
-     mkint(CLOCK_PROCESS_CPUTIME_ID),
+     mkint(CLOCK_VIRTUAL),
 #else
      mkvoid,
 #endif
