--- ksmp3play.c.orig	Mon Aug 20 04:43:37 2001
+++ ksmp3play.c	Sun Dec 29 11:01:56 2002
@@ -22,6 +22,7 @@
 #include "ksmp3play.h"
 #include <smpeg/smpeg.h>
 #include <curses.h>
+#include <sys/time.h>
 #include <sys/resource.h>
 #include <string.h>
 #include <ctype.h>
