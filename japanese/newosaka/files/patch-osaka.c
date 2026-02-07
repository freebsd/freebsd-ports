--- osaka.c.orig	1996-05-18 15:47:59 UTC
+++ osaka.c
@@ -11,7 +11,7 @@ char  **argv; 
 	char inbuf[8192], outbuf[8400];
 	char inmoji, henmoji;
 
-	while(gets(inbuf) != NULL)
+	while(fgets(inbuf, sizeof(inbuf), stdin) != NULL)
 	{
 		inmoji = inbuf[0];
 		inmoji2 = (unsigned long)inmoji & 0x0ff;
