--- tests/test-input-parsers.c.orig	2025-03-02 15:03:58 UTC
+++ tests/test-input-parsers.c
@@ -170,7 +170,7 @@ test_parse_iso8601_time (void)
 				 "   got: HH=%d MM=%d SS=%d FF=%ld TZ=%ld\n",
 				 td.in_string,
 				 td.hour, td.minute, td.second,
-				 td.fraction, td.timezone,
+				 td.fraction, (long)td.timezone,
 				 gda_time_get_hour (time), gda_time_get_minute (time), gda_time_get_second (time),
 				 gda_time_get_fraction (time), gda_time_get_timezone (time));
 		g_assert (gda_time_get_hour (time) == td.hour);
@@ -220,12 +220,12 @@ test_parse_iso8601_timestamp (void)
 					 "   exp: DD=%d MM=%d YYYY=%d HH=%d MM=%d SS=%d FF=%ld TZ=%ld\n"
 					 "   got: DD=%d MM=%d YYYY=%d HH=%d MM=%d SS=%d FF=%ld TZ=%ld\n",
 					 str, td.exp_day, td.exp_month, td.exp_year,
-					 tt.hour, tt.minute, tt.second, tt.fraction, tt.timezone,
+					 tt.hour, tt.minute, tt.second, tt.fraction, (long)tt.timezone,
 					 g_date_time_get_year (timestamp), g_date_time_get_month (timestamp),
 					 g_date_time_get_day_of_month (timestamp), g_date_time_get_hour (timestamp), g_date_time_get_minute (timestamp),
 					 g_date_time_get_second (timestamp),
 					 (glong) (g_date_time_get_seconds (timestamp) - g_date_time_get_second (timestamp)) / 1000000l,
-					 g_date_time_get_utc_offset (timestamp)/1000000);
+					 (long)g_date_time_get_utc_offset (timestamp)/1000000);
 					 
 				g_free (str);
 				return FALSE;
@@ -343,7 +343,7 @@ test_time_handler (void)
 				 "   got: HH=%d MM=%d SS=%d FF=%ld TZ=%ld\n",
 				 td.in_string,
 				 td.hour, td.minute, td.second,
-				 td.fraction, td.timezone,
+				 td.fraction, (long)td.timezone,
 				 gda_time_get_hour (ptime), gda_time_get_minute (ptime), gda_time_get_second (ptime),
 				 gda_time_get_fraction (ptime), gda_time_get_timezone (ptime));
 			return FALSE;
@@ -377,7 +377,7 @@ test_time_handler (void)
 				 "   got: HH=%d MM=%d SS=%d FF=%ld TZ=%ld\n",
 				 td.in_string,
 				 td.hour, td.minute, td.second,
-				 td.fraction, td.timezone,
+				 td.fraction, (long)td.timezone,
 				 gda_time_get_hour (ptime), gda_time_get_minute (ptime), gda_time_get_second (ptime),
 				 gda_time_get_fraction (ptime), gda_time_get_timezone (ptime));
 			return FALSE;
@@ -430,7 +430,7 @@ test_timestamp_handler (void)
 						 "   exp: DD=%d MM=%d YYYY=%d HH=%d MM=%d SS=%d FF=%ld TZ=%ld\n"
 						 "   got: DD=%d MM=%d YYYY=%d HH=%d MM=%d SS=%d FF=%ld (SF=%f) TZ=%ld\n",
 						 td.exp_day, td.exp_month, td.exp_year,
-						 tt.hour, tt.minute, tt.second, tt.fraction, tt.timezone,
+						 tt.hour, tt.minute, tt.second, tt.fraction, (long)tt.timezone,
 						 g_date_time_get_day_of_month (timestamp),
 						 g_date_time_get_month (timestamp),
 						 g_date_time_get_year (timestamp),
@@ -438,7 +438,7 @@ test_timestamp_handler (void)
 					 g_date_time_get_second (timestamp),
 					 (glong) ((g_date_time_get_seconds (timestamp) - g_date_time_get_second (timestamp)) * 1000000.0),
 					 g_date_time_get_seconds (timestamp),
-					 g_date_time_get_utc_offset (timestamp)/1000000);
+					 (long)g_date_time_get_utc_offset (timestamp)/1000000);
 
 				g_assert (g_date_time_get_year (timestamp) == td.exp_year);
 				g_assert (g_date_time_get_month (timestamp) == (gint) td.exp_month);
@@ -491,12 +491,12 @@ test_timestamp_handler (void)
 						 "   exp: DD=%d MM=%d YYYY=%d HH=%d MM=%d SS=%d FF=%ld TZ=%ld\\n"
 						 "   got: DD=%d MM=%d YYYY=%d HH=%d MM=%d SS=%d FF=%ld TZ=%ld\\n",
 						 str, td.exp_day, td.exp_month, td.exp_year,
-						 tt.hour, tt.minute, tt.second, tt.fraction, tt.timezone,
+						 tt.hour, tt.minute, tt.second, tt.fraction, (long)tt.timezone,
 						 g_date_time_get_year (timestamp), g_date_time_get_month (timestamp),
 						 g_date_time_get_day_of_month (timestamp), g_date_time_get_hour (timestamp), g_date_time_get_minute (timestamp),
 						 g_date_time_get_second (timestamp),
 						 (glong) ((g_date_time_get_seconds (timestamp) - g_date_time_get_second (timestamp)) * 1000000.0),
-						 g_date_time_get_utc_offset (timestamp)/1000000);
+						 (long)g_date_time_get_utc_offset (timestamp)/1000000);
 
 					g_object_unref (dh);
 					g_free (str);
