--- lib/dynxdr/xdrutil.c.orig	2026-01-27 11:15:15 UTC
+++ lib/dynxdr/xdrutil.c
@@ -102,7 +102,7 @@ XdrUtil_Deserialize(const void *data,  // IN
    ASSERT(dest != NULL);
 
    xdrmem_create(&xdrs, (char *) data, dataLen, XDR_DECODE);
-   ret = (Bool) proc(&xdrs, dest, 0);
+   ret = (Bool) proc(&xdrs, dest);
    xdr_destroy(&xdrs);
 
    if (!ret) {
