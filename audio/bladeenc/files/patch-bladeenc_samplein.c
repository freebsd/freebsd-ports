--- bladeenc/samplein.c.orig	Tue May  8 14:11:53 2001
+++ bladeenc/samplein.c	Wed Feb  5 20:18:03 2003
@@ -31,6 +31,7 @@
 #include	<stdio.h>
 #include	<stdlib.h>
 #include	<string.h>
+#include	<sys/types.h>
 
 #include	"system.h"
 #include	"samplein.h"
@@ -75,7 +76,7 @@
 static	int				initAIFF (SI_Stream *psInfo);
 static	uint			readAIFFSamples (SI_Stream *psInfo, int nSamples, short *wpSamples);
 
-static	int				myFseek (FILE *fp, int offset);
+static	int				myFseek (FILE *fp, unsigned int offset);
 
 
 
@@ -613,7 +614,7 @@
 
 /* We can't use the real fseek() since you can't seek in a stream (stdin) */
 
-static int					myFseek (FILE *fp, int offset)
+static int					myFseek (FILE *fp, unsigned int offset)
 {
 	char					dummy[256];
 
