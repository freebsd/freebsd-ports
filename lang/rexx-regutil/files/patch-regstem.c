--- regstem.c.orig	2004-06-15 19:15:06 UTC
+++ regstem.c
@@ -53,7 +53,7 @@ static int rxstrcasecmp(const PRXSTRING 
 {
    register int len = min(l->strlength, r->strlength),
                 d = l->strlength - r->strlength,
-                c = casecmp(l->strptr, r->strptr, len);
+                c = casecmp((unsigned char *) l->strptr, (unsigned char *) r->strptr, len);
    
    return (len && c) ? c : d;
 }
