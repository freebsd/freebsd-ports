--- src/plugins/ao/ao.c.orig	2011-10-20 19:26:08 UTC
+++ src/plugins/ao/ao.c
@@ -162,6 +162,7 @@ xmms_ao_new (xmms_output_t *output)
 
 		/* let's just use some common format to check if the device
 		 * name is valid */
+		memset(&format, 0, sizeof(format));
 		format.bits = 16;
 		format.rate = 44100;
 		format.channels = 2;
