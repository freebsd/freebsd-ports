--- logview/logview-utils.c.orig	2009-03-21 17:22:41.000000000 -0400
+++ logview/logview-utils.c	2009-03-21 17:23:22.000000000 -0400
@@ -136,7 +136,7 @@ log_read_dates (const char **buffer_line
 {
   int current_year, offsetyear, i, n, rangemin, rangemax, timestamp_len = 0;
   GSList *days = NULL;
-  GDate *date, *newdate;
+  GDate *date = NULL, *newdate;
   struct tm *tmptm;
   char *date_string;
   Day *day;
