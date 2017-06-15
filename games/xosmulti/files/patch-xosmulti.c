--- xosmulti.c.orig	2017-03-22 15:54:32 UTC
+++ xosmulti.c
@@ -22,6 +22,7 @@ static char	Usage[] = { 
 
 #include	<stdio.h>
 #include	<stdlib.h>
+#include	<string.h>
 #include	<sys/time.h>
 
 #include	<X11/Xlib.h>
@@ -76,7 +77,7 @@ extern char	*QuitMsg;	/* 終了時のメッセージ */
 /******** External Function ********/
 
 /* in image.c */
-extern unsigned int	GetDepth( );
+extern unsigned int	GetXDepth( );
 extern XImage	*CreateMyImage( );
 extern Cursor	CreateMyCursor( );
 
@@ -419,7 +420,7 @@ void	GetArgs( argc, argv )
 
 			XPosRatio = atoi( argv[i] );
 			if( XPosRatio < 0 || 100 < XPosRatio )
-			{	fprintf( stderr, "WARNING: xpos(%) must be in 0-100, use default\n" );
+			{	fprintf( stderr, "WARNING: xpos(%%) must be in 0-100, use default\n" );
 				XPosRatio = XPOS_RATIO;
 			}
 		}
@@ -1109,7 +1110,7 @@ void	Do_Talk( str )
 
 	n_line = AppendTalk( theFont, str );
 	talk_height = n_line * FontHeight;
-	talk_width = MaxTalkWidth( theFont );
+	talk_width = MaxTalkWidth( );
 	talk_width = talk_width * 9 >> 3; /* 横幅を 9/8 倍する */
 
 	TalkShape( Disp, TalkWin, talk_width, talk_height, 0 );
