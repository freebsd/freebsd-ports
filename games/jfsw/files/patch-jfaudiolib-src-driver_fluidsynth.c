Allow definition of clockid_t from within time.h, included by pthread.h

--- jfaudiolib/src/driver_fluidsynth.c.orig	2020-09-03 06:19:21 UTC
+++ jfaudiolib/src/driver_fluidsynth.c
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
