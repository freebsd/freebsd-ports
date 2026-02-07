--- regini.c.orig	2004-07-19 00:09:52 UTC
+++ regini.c
@@ -1002,7 +1002,7 @@ rxfunc(sysgeterrortext)
       result->strlength = 0;
    }
 #else
-   if (rcs = strerror(rc)) {
+   if ((rcs = strerror(rc))) {
       result->strlength = strlen(rcs);
       memcpy(result->strptr, rcs, result->strlength);
    }
