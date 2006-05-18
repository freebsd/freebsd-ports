--- ./src/cl_parse.c.orig	Thu Nov  3 16:06:26 2005
+++ ./src/cl_parse.c	Tue May 16 14:33:39 2006
@@ -974,7 +974,7 @@
 			cl.looptrack = MSG_ReadByte ();
 			if ((cls.demoplayback || cls.demorecording) && (cls.forcetrack != -1)) {
 //QuDos- cd tracks randomplay support ### FIXME ### tracks stop when changing levels
-#ifdef __linux__
+#ifdef __unix__
 	  			CDAudio_RandomPlay();
 #endif
 //-QuDos
