--- src/p_blowfish.c.orig	2016-06-20 14:41:27 UTC
+++ src/p_blowfish.c
@@ -27,16 +27,21 @@
 static char rcsid[] = "@(#)$Id: p_blowfish.c,v 1.3 2005/06/04 18:00:14 hisi Exp $";
 #endif
 
+#include <p_global.h>
+/*
 #include <stdio.h>
 #include <string.h>
 #include <config.h>
 
 char *strmncpy(char *dest, char *source, size_t len);
 char *lngtxt(int msgnum);
+*/
 
+/*
 #define pcontext { strmncpy(ctxt,__FILE__,sizeof(ctxt));strmncpy(cfunc,__FUNCTION__,sizeof(cfunc)); cline=__LINE__; }
 #define pmalloc(n) __pmalloc((n),__FILE__,__FUNCTION__,__LINE__)
 #define free(n) _pfree(n,__FILE__,__FUNCTION__,__LINE__)
+*/
 
 unsigned char *hashstring(unsigned char *str,int len);
 unsigned char *unhashstring(unsigned char *str);
@@ -478,10 +483,11 @@ char * BLOWencrypt(unsigned char *str)
    char *p, *s, *dest, *d, *pt;
    char rim[5],ep[5],rep[5];
    int i;
-   dest = (char *) pmalloc((strlen(str) + 9) * 2);
+   dest = __pmalloc((strlen(str) + 9) * 2, "p_blowfish.c", "BLOWencrypt", 481);
+   dest = pmalloc((strlen(str) + 9) * 2);
    *dest=0;
    /* pad fake string with 8 bytes to make sure there's enough */
-   s = (char *) pmalloc(strlen(str) + 9);
+   s =  pmalloc(strlen(str) + 9);
    strcpy(s, str);
    p = s;
    while (*p)
