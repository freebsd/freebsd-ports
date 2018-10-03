--- ps_tiny.c.orig	2014-09-16 08:52:28 UTC
+++ ps_tiny.c
@@ -1,10 +1,3 @@
-#define DUMMY \
-set -ex; \
-gcc -O3 -s -DNDEBUG=1 -DNO_CONFIG=1 -ansi -pedantic -Wunused \
-  -Wall -W -Wstrict-prototypes -Wtraditional -Wnested-externs -Winline \
-  -Wpointer-arith -Wbad-function-cast -Wcast-qual -Wmissing-prototypes \
-  -Wmissing-declarations ps_tiny.c -o ps_tiny; \
-exit
 /* ps_tiny.c -- read .pin files, write short PostScript code
  * by pts@fazekas.hu at Sat Aug 24 12:46:14 CEST 2002
  * -- Sat Aug 24 18:23:08 CEST 2002
