--- dq/dqcache-start.c.orig	2016-12-07 17:33:44 UTC
+++ dq/dqcache-start.c
@@ -1,7 +1,11 @@
 #include <unistd.h>
 #include <sys/types.h>
 #include <pwd.h>
+/*
+workaround for *BSD
 #include <stdlib.h>
+*/
+extern int setenv(const char *, const char *, int);
 #include "numtostr.h"
 #include "strtonum.h"
 #include "e.h"
