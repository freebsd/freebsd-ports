--- textEncoding/sioIconv.c.orig	2013-02-01 12:11:08 UTC
+++ textEncoding/sioIconv.c
@@ -61,11 +61,7 @@ static int sioInIconvReadBytes(	void *		
     /*  1  */
     while( ! tooBig )
 	{
-#	if defined(__GNUC__) && ! defined(iconv)
 	char *		inbuf= (char *)iis->iisInBuf;
-#	else
-	const char *	inbuf= (const char *)iis->iisInBuf;
-#	endif
 	int		got;
 
 	/*  2  */
