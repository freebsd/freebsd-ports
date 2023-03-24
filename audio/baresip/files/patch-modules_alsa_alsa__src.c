--- modules/alsa/alsa_src.c.orig	2022-05-01 07:27:33 UTC
+++ modules/alsa/alsa_src.c
@@ -4,7 +4,7 @@
  * Copyright (C) 2010 Alfred E. Heggestad
  */
 #define _DEFAULT_SOURCE 1
-#define _POSIX_SOURCE 1
+#define _POSIX_C_SOURCE 200112L
 #include <sys/types.h>
 #include <sys/time.h>
 #include <stdlib.h>
