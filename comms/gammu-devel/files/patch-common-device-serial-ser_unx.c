--- common/device/serial/ser_unx.c.orig	Fri Aug 13 12:10:45 2004
+++ common/device/serial/ser_unx.c	Fri Nov 26 16:25:16 2004
@@ -230,6 +230,7 @@
 		case 57600:	speed2 = B57600;	break;
 		case 115200:	speed2 = B115200;	break;
 		case 230400:	speed2 = B230400;	break;
+#ifdef B460800
 		case 460800:	speed2 = B460800;	break;
 #ifdef B500000
 		case 500000:	speed2 = B500000;	break;
@@ -243,6 +244,7 @@
 		case 3000000:	speed2 = B3000000;	break;
 		case 3500000:	speed2 = B3500000;	break;
 		case 4000000:	speed2 = B4000000;	break;	
+#endif
 #endif
 #endif
 	}
