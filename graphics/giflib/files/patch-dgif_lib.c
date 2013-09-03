--- lib/dgif_lib.c.orig	2013-08-29 21:48:51.000000000 +0200
+++ lib/dgif_lib.c	2013-09-03 05:58:21.000000000 +0200
@@ -149,7 +149,7 @@
         fclose(f);
         free((char *)Private);
         free((char *)GifFile);
-	*Error = D_GIF_ERR_NO_SCRN_DSCR;
+	_GifError = D_GIF_ERR_NO_SCRN_DSCR;
         return NULL;
     }
 
