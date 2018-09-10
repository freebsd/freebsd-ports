--- libdrizzle/statement_param.cc.orig	2018-08-27 19:24:50 UTC
+++ libdrizzle/statement_param.cc
@@ -599,11 +599,11 @@ char *long_to_string(drizzle_bind_st *param, uint32_t 
   char* buffer= param->data_buffer + 50;
   if (param->options.is_unsigned)
   {
-    snprintf(buffer, 12, "%"PRIu32, val);
+    snprintf(buffer, 12, "%" PRIu32, val);
   }
   else
   {
-    snprintf(buffer, 12, "%"PRId32, (int32_t)val);
+    snprintf(buffer, 12, "%" PRId32, (int32_t)val);
   }
   return buffer;
 }
@@ -614,11 +614,11 @@ char *longlong_to_string(drizzle_bind_st *param, uint6
   char* buffer= param->data_buffer + 50;
   if (param->options.is_unsigned)
   { 
-    snprintf(buffer, 21, "%"PRIu64, val);
+    snprintf(buffer, 21, "%" PRIu64, val);
   }
   else
   {
-    snprintf(buffer, 21, "%"PRId64, (int64_t)val);
+    snprintf(buffer, 21, "%" PRId64, (int64_t)val);
   }
   return buffer;
 }
@@ -639,7 +639,7 @@ char *time_to_string(drizzle_bind_st *param, drizzle_d
   int used = 0;
     
   /* Values are transferred with days separated from hours, but presented with days folded into hours. */
-  used = snprintf(buffer, buffersize-used, "%s%02u:%02"PRIu8":%02"PRIu8, (time->negative) ? "-" : "", time->hour + 24 * time->day, time->minute, time->second);
+  used = snprintf(buffer, buffersize-used, "%s%02u:%02" PRIu8 ":%02" PRIu8, (time->negative) ? "-" : "", time->hour + 24 * time->day, time->minute, time->second);
 
   /* TODO: the existence (and length) of the decimals should be decided based on the number of fields sent by the server or possibly the column's "decimals" value, not by whether the microseconds are 0 */
   if (time->microsecond || time->show_microseconds)
@@ -657,19 +657,19 @@ char *timestamp_to_string(drizzle_bind_st *param, driz
   int buffersize = 27;
   int used = 0;
   
-  used += snprintf(buffer, buffersize-used, "%04"PRIu16"-%02"PRIu8"-%02"PRIu32,
+  used += snprintf(buffer, buffersize-used, "%04" PRIu16 "-%02" PRIu8 "-%02" PRIu32,
      timestamp->year, timestamp->month, timestamp->day);
   assert(used < buffersize);
   
   if (param->type == DRIZZLE_COLUMN_TYPE_DATE)
     return buffer;
   
-  used += snprintf(buffer+used, buffersize-used, " %02"PRIu16":%02"PRIu8":%02"PRIu8,
+  used += snprintf(buffer+used, buffersize-used, " %02" PRIu16 ":%02" PRIu8 ":%02" PRIu8,
     timestamp->hour, timestamp->minute, timestamp->second);
 
   if (timestamp->microsecond || timestamp->show_microseconds)
   {
-    used += snprintf(buffer+used, buffersize-used, ".%06"PRIu32, timestamp->microsecond);
+    used += snprintf(buffer+used, buffersize-used, ".%06" PRIu32, timestamp->microsecond);
   }
   
   assert(used < buffersize);
