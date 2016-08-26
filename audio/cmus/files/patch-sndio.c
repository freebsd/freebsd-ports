Upstreamed in https://github.com/cmus/cmus/commit/37f4daaea4d2724cd2b4d66984cf72b012ef5d48 
--- sndio.c.orig	2015-07-13 10:00:56 UTC
+++ sndio.c
@@ -20,7 +20,6 @@
 
 #include <sys/types.h>
 #include <sys/ioctl.h>
-#include <sys/audioio.h>
 #include <sys/stat.h>
 #include <errno.h>
 #include <fcntl.h>
@@ -82,6 +81,12 @@ static int sndio_set_sf(sample_format_t 
 		par.le = 1;
 
 	switch (sf_get_bits(sndio_sf)) {
+	case 32:
+		par.bits = 32;
+		break;
+	case 24:
+		par.bits = 24;
+		break;
 	case 16:
 		par.bits = 16;
 		break;
