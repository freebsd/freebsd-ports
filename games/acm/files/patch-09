--- dis/lib/xdr_var_array.c~	Mon May 11 20:58:55 1998
+++ dis/lib/xdr_var_array.c	Sun Jul  6 03:21:47 2003
@@ -75,6 +75,12 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <sys/param.h>
+#if __FreeBSD_Version__ >= 500113
+#  include <sys/limits.h>
+#else
+#  include <machine/limits.h>
+#endif
 #include <rpc/types.h>
 #include <rpc/xdr.h>
 
@@ -104,7 +110,7 @@
 	register u_int nodesize;
 
 	c = size;
-	if ((c > maxsize) && (xdrs->x_op != XDR_FREE)) {
+	if ((c > maxsize || c > UINT_MAX/elsize) && (xdrs->x_op != XDR_FREE)) {
 		return (FALSE);
 	}
 	nodesize = c * elsize;
