--- clients/memaslap.c.orig	2020-08-22 10:06:16 UTC
+++ clients/memaslap.c
@@ -45,6 +45,11 @@
 #define OPTIONSTRING const char*
 #endif
 
+/* global variables */
+ms_global_t ms_global;
+ms_statistic_t ms_statistic;
+ms_stats_t ms_stats;
+
 /* options */
 static struct option long_options[]=
 {
