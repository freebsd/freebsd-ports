--- dis/lib/xdr_var_array.c.orig	1998-05-12 03:58:55 UTC
+++ dis/lib/xdr_var_array.c
@@ -75,6 +75,7 @@ static char *rcsid = "$Id: xdr_var_array.c,v 1.2 1998/
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <limits.h>
 #include <rpc/types.h>
 #include <rpc/xdr.h>
 
@@ -104,7 +105,7 @@ xdr_var_array(register XDR * xdrs, caddr_t * addrp, u_
 	register u_int nodesize;
 
 	c = size;
-	if ((c > maxsize) && (xdrs->x_op != XDR_FREE)) {
+	if ((c > maxsize || c > UINT_MAX/elsize) && (xdrs->x_op != XDR_FREE)) {
 		return (FALSE);
 	}
 	nodesize = c * elsize;
