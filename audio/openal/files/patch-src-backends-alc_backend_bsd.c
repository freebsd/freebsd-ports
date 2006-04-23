--- src/backends/alc_backend_bsd.c.orig	Sat Apr 22 12:25:15 2006
+++ src/backends/alc_backend_bsd.c	Sat Apr 22 12:26:15 2006
@@ -9,7 +9,10 @@
  */
 #include "al_siteconfig.h"
 
+#define __BSD_VISIBLE 1
+
 #include <AL/al.h>
+#include <AL/alext.h>
 #include <assert.h>
 #include <fcntl.h>
 #include <sys/soundcard.h>
