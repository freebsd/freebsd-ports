--- src/plugins/ao/ao.c.orig
+++ src/plugins/ao/ao.c
@@ -160,6 +160,7 @@
 
 		/* let's just use some common format to check if the device
 		 * name is valid */
+		memset(&format, 0, sizeof(format));
 		format.bits = 16;
 		format.rate = 44100;
 		format.channels = 2;
