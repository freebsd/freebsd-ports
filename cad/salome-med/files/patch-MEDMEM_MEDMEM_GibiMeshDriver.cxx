--- src/MEDMEM/MEDMEM_GibiMeshDriver.cxx.orig	2010-11-07 16:46:10.000000000 +0600
+++ src/MEDMEM/MEDMEM_GibiMeshDriver.cxx	2010-11-07 16:46:22.000000000 +0600
@@ -29,6 +29,7 @@
 #ifdef HAS_XDR
 // On windows, this file must be included first otherwise
 // there is a conflict with the symbol GROUP when compiling the xdr support ...
+#include <rpc/types.h>
 #include <rpc/xdr.h>
 #endif
 
