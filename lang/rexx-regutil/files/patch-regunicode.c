--- regunicode.c.orig	2003-04-01 20:08:34 UTC
+++ regunicode.c
@@ -542,10 +542,10 @@ rxfunc(systounicode)
    /* for the same reason, perform utf-7 and utf-8 conversions here, rather
     * than using iconv() */
    else if (cp == CP_UTF7) {
-      outs.strlength = u7tou((unsigned short *)outs.strptr,  argv[0].strptr, argv[0].strlength);
+      outs.strlength = u7tou((unsigned short *)outs.strptr,  (unsigned char *) argv[0].strptr, argv[0].strlength);
    }
    else if (cp == CP_UTF8) {
-      outs.strlength = u8tou((unsigned short *) outs.strptr, argv[0].strptr, argv[0].strlength);
+      outs.strlength = u8tou((unsigned short *) outs.strptr, (unsigned char *) argv[0].strptr, argv[0].strlength);
    }
 
    /* if requesting a specific code page, we need iconv, or we return an
@@ -719,10 +719,10 @@ rxfunc(sysfromunicode)
    /* for the same reason, perform utf-7 and utf-8 conversions here, rather
     * than using iconv() */
    else if (cp == CP_UTF7) {
-      outs.strlength = utou7(outs.strptr,  (unsigned short *)argv[0].strptr, argv[0].strlength/2);
+      outs.strlength = utou7((unsigned char *) outs.strptr,  (unsigned short *)argv[0].strptr, argv[0].strlength/2);
    }
    else if (cp == CP_UTF8) {
-      outs.strlength = utou8(outs.strptr, (unsigned short *)argv[0].strptr, argv[0].strlength/2);
+      outs.strlength = utou8((unsigned char *) outs.strptr, (unsigned short *)argv[0].strptr, argv[0].strlength/2);
    }
 
    /* if requesting a specific code page, we need iconv, or we return an
