--- fileio.c.orig	2009-04-20 00:03:44 UTC
+++ fileio.c
@@ -2240,8 +2240,11 @@ int do_string(__G__ length, option)   /*
 
         /* translate the Zip entry filename coded in host-dependent "extended
            ASCII" into the compiler's (system's) internal text code page */
+#if 0
+/* cnoize is lazy to read it carefully */
         Ext_ASCII_TO_Native(G.filename, G.pInfo->hostnum, G.pInfo->hostver,
                             G.pInfo->HasUxAtt, (option == DS_FN_L));
+#endif
 
         if (G.pInfo->lcflag)      /* replace with lowercase filename */
             STRLOWER(G.filename, G.filename);
