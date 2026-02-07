--- sample/sample.c.orig	2019-02-01 11:18:44 UTC
+++ sample/sample.c
@@ -2,7 +2,7 @@
 #include <math.h>
 #include <signal.h>
 #include <stdio.h>
-#include "..\lib\Remotery.h"
+#include <Remotery.h>
 
 void aggregateFunction() {
     rmt_BeginCPUSample(aggregate, RMTSF_Aggregate);
