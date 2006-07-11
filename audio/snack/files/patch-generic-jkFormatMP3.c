--- ../generic/jkFormatMP3.c.orig	Mon Jul 10 22:17:06 2006
+++ ../generic/jkFormatMP3.c	Mon Jul 10 22:17:17 2006
@@ -31,7 +31,6 @@
 #include <string.h>
 #define FRAS2(is,a) ((is) > 0 ? t_43[(is)]*(a):-t_43[-(is)]*(a))
 #define MAXFRAMESIZE 2106  /* frame size starting at header */
-#define roundf(x) (floor((x)+(float )0.5f))
 static char *gblOutputbuf;
 static char *gblReadbuf;
 static int gblBufind = 0;
@@ -1311,6 +1310,7 @@
 
 #include <math.h>
 
+#define roundf(x) (floor((x)+(float )0.5f))
 #define PI12      0.261799387f
 #define PI36      0.087266462f
 #define COSPI3    0.500000000f
