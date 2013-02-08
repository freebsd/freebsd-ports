--- cnv/giftorle.c.orig	1993-10-18 22:59:37.000000000 +0900
+++ cnv/giftorle.c	2012-10-16 00:54:53.000000000 +0900
@@ -22,6 +22,10 @@
 /* +------------------------------------------------------------------+ */
 
 #include	<stdio.h>
+#include	<stdlib.h>
+#include	<string.h>
+#include	<unistd.h>
+
 #include	"rle.h"
 
 #ifndef lint
@@ -69,7 +73,7 @@
 
 static int output_colormap = FALSE;
 
-void
+int
 main(argc,argv)
 int	argc;
 char	**argv;
@@ -96,7 +100,7 @@
 
     while ( nfname-- > 0 )
 	(void)ReadGIF( *infname++ );
-    exit( 0 );
+    return( 0 );
 }
 
 int
@@ -203,7 +207,7 @@
 	    EasyFail("EOF in extention\n",TRUE);
 	if (c == 0)
 	    return FALSE;
-	if (read(fd,buf,(int) c)!=(int) c) 
+	if (read(fileno(fd),buf,(int) c)!=(int) c) 
 	    EasyFail("EOF in extention\n",TRUE);
     }
 }
@@ -278,7 +282,7 @@
 	max_code_size = 2*clear_code;
 	max_code = clear_code+2;
 
-	GetCode(fd,NULL,TRUE);
+	GetCode(fd,0,TRUE);
 		
 	fresh=TRUE;
 
