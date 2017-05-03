--- bitbang.c.orig	2017-03-30 13:30:41 UTC
+++ bitbang.c
@@ -331,7 +331,7 @@ int bitbang_cmd(PROGRAMMER * pgm, const unsigned char 
     res[i] = bitbang_txrx(pgm, cmd[i]);
   }
 
-    if(verbose >= 2)
+    if(verbose > 4)
 	{
         avrdude_message(MSG_NOTICE2, "bitbang_cmd(): [ ");
         for(i = 0; i < 4; i++)
