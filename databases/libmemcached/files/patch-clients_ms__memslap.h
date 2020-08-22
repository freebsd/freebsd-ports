--- clients/ms_memslap.h.orig	2020-08-22 10:06:28 UTC
+++ clients/ms_memslap.h
@@ -116,14 +116,14 @@ typedef struct global
   bool time_out;
 } ms_global_t;
 
-/* global structure */
-ms_global_t ms_global;
+/* global structure, defined in memaslap.c */
+extern ms_global_t ms_global;
 
-/* global stats information structure */
-ms_stats_t ms_stats;
+/* global stats information structure, defined in memaslap.c */
+extern ms_stats_t ms_stats;
 
-/* global statistic structure */
-ms_statistic_t ms_statistic;
+/* global statistic structure, defined in mamaslap.c */
+extern ms_statistic_t ms_statistic;
 
 #ifdef __cplusplus
 }
