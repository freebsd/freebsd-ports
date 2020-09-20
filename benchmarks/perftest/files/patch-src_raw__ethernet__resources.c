--- src/raw_ethernet_resources.c.orig	2019-07-28 11:18:47 UTC
+++ src/raw_ethernet_resources.c
@@ -55,7 +55,7 @@
 #include <config.h>
 #endif
 
-struct perftest_parameters* duration_param;
+extern struct perftest_parameters* duration_param;
 
 int check_flow_steering_support(char *dev_name)
 {
