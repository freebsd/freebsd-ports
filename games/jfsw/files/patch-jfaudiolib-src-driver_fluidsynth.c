Allow definition of clockid_t from within time.h, included by pthread.h

--- jfaudiolib/src/driver_fluidsynth.c.orig	2014-11-17 09:33:38.377936840 +0100
+++ jfaudiolib/src/driver_fluidsynth.c	2014-11-17 18:56:05.694804967 +0100
@@ -29,7 +29,10 @@
 #include <string.h>
 #include <stdio.h>
 #include <stdlib.h>
+
+#define __POSIX_VISIBLE 199309
 #include <pthread.h>
+
 #include <sys/select.h>
 #include <math.h>
 #include <unistd.h>
