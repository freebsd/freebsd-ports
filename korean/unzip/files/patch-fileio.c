--- fileio.c.orig	Sun Feb 17 14:43:28 2002
+++ fileio.c	Wed May 21 03:40:24 2003
@@ -2135,8 +2135,9 @@
 
         /* translate the Zip entry filename coded in host-dependent "extended
            ASCII" into the compiler's (system's) internal text code page */
-        Ext_ASCII_TO_Native(G.filename, G.pInfo->hostnum, G.pInfo->hostver,
-                            G.pInfo->HasUxAtt, (option == DS_FN_L));
+	if (!uO.dotflag)
+	    Ext_ASCII_TO_Native(G.filename, G.pInfo->hostnum, G.pInfo->hostver,
+				G.pInfo->HasUxAtt, (option == DS_FN_L));
 
         if (G.pInfo->lcflag)      /* replace with lowercase filename */
             STRLOWER(G.filename, G.filename);
