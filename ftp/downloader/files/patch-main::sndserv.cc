--- main/sndserv.cc.orig	Mon Jan 27 13:40:08 2003
+++ main/sndserv.cc	Fri Mar 21 14:48:47 2003
@@ -153,7 +153,7 @@
 
 #if G_BYTE_ORDER == G_LITTLE_ENDIAN
 	*len =(buf[3] << 24) | (buf[2] << 16) | (buf[1] << 8) | buf[0];
-#elif
+#else
 	*len =(buf[0] << 24) | (buf[1] << 16) | (buf[2] << 8) | buf[3];
 #endif
 
@@ -166,7 +166,7 @@
 		return 0;
 #if G_BYTE_ORDER == G_LITTLE_ENDIAN
 	*val = (buf[1] << 8) | buf[0];
-#elif
+#else
 	*val = (buf[0] << 8) | buf[1];
 #endif
 	return 1;
