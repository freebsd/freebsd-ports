--- src/arch/shared/iodrv/io-unix-access.c.orig	2022-12-27 23:56:56 UTC
+++ src/arch/shared/iodrv/io-unix-access.c
@@ -26,6 +26,15 @@
 
 #include "vice.h"
 
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#if defined(__ppc__)
+#include <machine/pio.h>
+#else
+#include <machine/iodev.h>
+#endif
+#endif
+
 #ifdef UNIX_COMPILE
 
 #include <fcntl.h>
@@ -121,8 +130,12 @@ static uint8_t device_io_inb(uint16_t addr)
 #ifdef HAVE_INBV
     return inbv(addr);
 #else
+#ifdef HAVE_INB
     return inb(addr);
+#else
+    return 0;
 #endif
+#endif
 }
 
 static void device_io_outb(uint16_t addr, uint8_t val)
@@ -130,7 +143,9 @@ static void device_io_outb(uint16_t addr, uint8_t val)
 #ifdef HAVE_OUTBV
     outbv(addr, val);
 #else
+#ifdef HAVE_OUTB
     outb(addr, val);
+#endif
 #endif
 }
 #endif
