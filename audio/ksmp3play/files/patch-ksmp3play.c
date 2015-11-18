--- ksmp3play.c.orig	2008-06-17 05:57:56 UTC
+++ ksmp3play.c
@@ -42,6 +42,7 @@
 #include "ksmp3play.h"
 #include <smpeg/smpeg.h>
 #include <curses.h>
+#include <sys/time.h>
 #include <sys/resource.h>
 #include <string.h>
 #include <ctype.h>
