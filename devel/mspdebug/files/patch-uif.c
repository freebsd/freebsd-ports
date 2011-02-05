--- uif.c.orig	Mon Nov  8 22:40:57 2010
+++ uif.c	Thu Dec  2 13:05:36 2010
@@ -25,7 +25,9 @@
 #include <unistd.h>
 #include <termios.h>
 
+#if defined(__linux__)
 #include <linux/serial.h>
+#endif
 #include <sys/ioctl.h>
 #include <fcntl.h>
 
@@ -33,7 +35,7 @@
 #include "util.h"
 #include "output.h"
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__)
 #define B460800 460800
 #define B500000 500000
 #endif
@@ -85,6 +87,7 @@ static void serial_destroy(transport_t tr_base)
 	free(tr);
 }
 
+#if defined(__linux__)
 static int open_olimex_iso(const char *device)
 {
         int fd = open(device, O_RDWR | O_NOCTTY);
@@ -112,6 +115,7 @@ static int open_olimex_iso(const char *device)
 
         return fd;
 }
+#endif
 
 transport_t uif_open(const char *device, uif_type_t type)
 {
@@ -138,8 +142,12 @@ transport_t uif_open(const char *device, uif_type_t ty
 		break;
 
 	case UIF_TYPE_OLIMEX_ISO:
+#if defined(__linux__)
 		printc("Trying to open Olimex (ISO) on %s...\n", device);
 		tr->serial_fd = open_olimex_iso(device);
+#else
+		printc_err("uif_open: ioctl TIOCSSERIAL not supported on this platform\n");
+#endif
 		break;
 	}
 
