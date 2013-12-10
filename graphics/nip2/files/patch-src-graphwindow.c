--- src/graphwindow.c.orig	2011-01-25 19:44:07.000000000 +0300
+++ src/graphwindow.c	2013-11-28 03:48:15.996694984 +0400
@@ -260,7 +260,7 @@
 
 	IM_FREEF( agclose, graphwindow->graph );
 
-	graphwindow->graph = agread( of->fp );
+	graphwindow->graph = agread( of->fp, NULL );
 
 	ifile_close( of );
 	unlinkf( "%s", tname );
