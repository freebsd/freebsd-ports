--- thirdparty/linuxbsd_headers/alsa/asoundlib.h.orig	2023-03-02 09:54:29 UTC
+++ thirdparty/linuxbsd_headers/alsa/asoundlib.h
@@ -38,7 +38,7 @@
 #include <poll.h>
 #include <errno.h>
 #include <stdarg.h>
-#include <endian.h>
+#include <sys/endian.h>
 
 #ifndef __GNUC__
 #define __inline__ inline
