--- uartlirc_lircdev.c.orig
+++ uartlirc_lircdev.c
@@ -33,6 +33,7 @@ __FBSDID("$FreeBSD$");
 #include <sys/conf.h>
 #include <sys/cons.h>
 #include <sys/fcntl.h>
+#include <sys/filio.h>
 #include <sys/interrupt.h>
 #include <sys/kernel.h>
 #include <sys/malloc.h>
@@ -117,6 +118,9 @@ uartlirc_lircdev_ioctl(struct cdev *dev,
 	case LIRC_GET_FEATURES:
 		*arg = LIRC_CAN_REC_MODE2;
 		return (0);
+	case FIONBIO:
+	case FIOASYNC:
+		return (0);
 	default:
 		return ENOTTY;
 	}
