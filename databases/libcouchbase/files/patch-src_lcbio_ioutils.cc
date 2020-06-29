--- src/lcbio/ioutils.cc.orig	2020-06-17 13:30:27 UTC
+++ src/lcbio/ioutils.cc
@@ -25,6 +25,7 @@
 #include "manager.h"
 #include "iotable.h"
 #include <stdio.h>
+#include <netinet/in.h>
 #include "ssl.h"
 
 lcbio_CSERR
