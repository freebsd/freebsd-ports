--- cnv/giftorle.c.orig	Mon Oct 18 08:59:37 1993
+++ cnv/giftorle.c	Thu Nov 29 10:42:17 2007
@@ -21,7 +21,10 @@
 /* |   don't try to make money off it, or pretend that you wrote it.  | */
 /* +------------------------------------------------------------------+ */
 
+#include	<stdlib.h>
 #include	<stdio.h>
+#include	<unistd.h>
+
 #include	"rle.h"
 
 #ifndef lint
@@ -69,7 +72,7 @@
 
 static int output_colormap = FALSE;
 
-void
+int
 main(argc,argv)
 int	argc;
 char	**argv;
@@ -96,7 +99,7 @@
 
     while ( nfname-- > 0 )
 	(void)ReadGIF( *infname++ );
-    exit( 0 );
+    return( 0 );
 }
 
 int
@@ -203,7 +206,7 @@
 	    EasyFail("EOF in extention\n",TRUE);
 	if (c == 0)
 	    return FALSE;
-	if (read(fd,buf,(int) c)!=(int) c) 
+	if (read(fileno(fd),buf,(int) c)!=(int) c) 
 	    EasyFail("EOF in extention\n",TRUE);
     }
 }
@@ -278,7 +281,7 @@
 	max_code_size = 2*clear_code;
 	max_code = clear_code+2;
 
-	GetCode(fd,NULL,TRUE);
+	GetCode(fd,0,TRUE);
 		
 	fresh=TRUE;
 
