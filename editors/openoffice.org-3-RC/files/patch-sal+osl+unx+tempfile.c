--- ../sal/osl/unx/tempfile.c.orig	Thu Apr  3 21:58:43 2003
+++ ../sal/osl/unx/tempfile.c	Thu Apr  3 21:59:08 2003
@@ -104,7 +104,7 @@
     if ( !pValue )
 	{
         pValue = getenv( "TMP" );
-#if defined(SOLARIS) || defined (LINUX)
+#if defined(SOLARIS) || defined (LINUX) || defined (FREEBSD)
 		if ( !pValue )
 			pValue = P_tmpdir;
 #endif
