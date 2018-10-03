--- pts_defl.c.orig	2008-08-29 05:16:47.000000000 +0900
+++ pts_defl.c	2010-03-19 05:54:55.000000000 +0900
@@ -1,10 +1,3 @@
-#define DUMMY \
-set -ex; \
-"${CC:-gcc}" -DNDEBUG=1 -DPTS_DEFL_MAIN -O3 -ansi \
-  -Wall -W -Wstrict-prototypes -Wtraditional -Wnested-externs -Winline \
-  -Wpointer-arith -Wbad-function-cast -Wcast-qual -Wmissing-prototypes \
-  -Wmissing-declarations pts_defl.c -o flateenc; \
-exit
 /*
  * pts_defl.c -- C source file ZIP compression ripped from linux-2.6.8.1
  * by pts@fazekas.hu at Tue Jan 18 15:19:06 CET 2005
