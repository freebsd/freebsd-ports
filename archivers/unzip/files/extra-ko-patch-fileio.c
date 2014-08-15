--- fileio.c.orig	2009-04-20 00:03:44 UTC
+++ fileio.c
@@ -2240,8 +2240,9 @@ int do_string(__G__ length, option)   /*
 
         /* translate the Zip entry filename coded in host-dependent "extended
            ASCII" into the compiler's (system's) internal text code page */
-        Ext_ASCII_TO_Native(G.filename, G.pInfo->hostnum, G.pInfo->hostver,
-                            G.pInfo->HasUxAtt, (option == DS_FN_L));
+	if (!uO.dotflag)
+	    Ext_ASCII_TO_Native(G.filename, G.pInfo->hostnum, G.pInfo->hostver,
+				G.pInfo->HasUxAtt, (option == DS_FN_L));
 
         if (G.pInfo->lcflag)      /* replace with lowercase filename */
             STRLOWER(G.filename, G.filename);
