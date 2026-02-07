--- Source/include/NCSMisc.h.orig	2009-04-05 22:05:50.000000000 +0400
+++ Source/include/NCSMisc.h	2009-04-05 22:06:31.000000000 +0400
@@ -59,7 +59,8 @@
 	NCS_LINUX	= 6,	/* Linux				*/
 	NCS_PALM	= 7,	/* PalmOS (v2+)				*/
 	NCS_SOLARIS	= 8,	/* Solaris 2.5+				*/
-	NCS_HPUX	= 9	/* HP-UX 11.0(64bit)			*/
+	NCS_HPUX	= 9,	/* HP-UX 11.0(64bit)			*/
+	NCS_FREEBSD	= 10	/* FreeBSD				*/
 } NCSPlatform;
 
 void NCSFormatSizeText(INT64 nSizeBytes, char *buf);
