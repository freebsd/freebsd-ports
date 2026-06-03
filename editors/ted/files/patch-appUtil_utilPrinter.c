--- appUtil/utilPrinter.c.orig	2013-02-01 12:11:08 UTC
+++ appUtil/utilPrinter.c
@@ -331,14 +331,14 @@ int utilPrinterGetPrinters(	int *			pPrinterCount,
     /*  1  */
     if  ( count == 0 )
 	{
-	utilPrinterGetLprPrinters(  "( lpc status ) 2>/dev/null",
+	utilPrinterGetLprPrinters(  "( lpc status all) 2>/dev/null",
 						&defaultPrinter, &count, &pd );
 	}
 
     /*  1b  */
     if  ( count == 0 )
 	{
-	utilPrinterGetLprPrinters(  "( /usr/sbin/lpc status ) 2>/dev/null",
+	utilPrinterGetLprPrinters(  "( /usr/sbin/lpc status all) 2>/dev/null",
 						&defaultPrinter, &count, &pd );
 	}
 
