--- src/linux/zfilew.c.orig	Tue May  1 21:33:14 2001
+++ src/linux/zfilew.c	Thu May  3 22:47:47 2001
@@ -365,6 +365,11 @@
 
    *(char *)(DTALocPos + 0x15) = 0;
 
+#ifdef __FreeBSD__
+   if (globbuf.gl_matchc == 0)
+	return -1;
+#endif
+
    stat ( globbuf.gl_pathv[globcur], &filetype );
    
    if(ZFileFindATTRIB&0x10 && !S_ISDIR ( filetype.st_mode )) return(ZFileFindNext());
