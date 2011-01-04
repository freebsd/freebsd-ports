--- src/Communication/SALOME_Comm_i.cxx.orig	2010-06-17 21:08:32.000000000 +0700
+++ src/Communication/SALOME_Comm_i.cxx	2010-11-15 15:55:02.000000000 +0600
@@ -22,8 +22,10 @@
 
 #include "SALOME_Comm_i.hxx"
 #ifndef WIN32
+#include <rpc/types.h>
 #include <rpc/xdr.h>
 #endif
+#include <cstdio>
 #include "omniORB4/poa.h"
 #include "omnithread.h"
 #include "Utils_SINGLETON.hxx"
