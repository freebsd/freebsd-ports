--- fileio.c.orig	Wed Jun  5 03:41:04 2002
+++ fileio.c	Wed Jun  5 03:44:33 2002
@@ -2135,8 +2135,11 @@
 
         /* translate the Zip entry filename coded in host-dependent "extended
            ASCII" into the compiler's (system's) internal text code page */
+#if 0
+/* cnoize is lazy to read it carefully */
         Ext_ASCII_TO_Native(G.filename, G.pInfo->hostnum, G.pInfo->hostver,
                             G.pInfo->HasUxAtt, (option == DS_FN_L));
+#endif
 
         if (G.pInfo->lcflag)      /* replace with lowercase filename */
             STRLOWER(G.filename, G.filename);
