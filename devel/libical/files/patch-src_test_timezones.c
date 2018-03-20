--- src/test/timezones.c.orig	2018-03-09 22:35:51 UTC
+++ src/test/timezones.c
@@ -1,15 +1,16 @@
 /*
 ======================================================================
 
-  The contents of this file are subject to the Mozilla Public License
-  Version 1.0 (the "License"); you may not use this file except in
-  compliance with the License. You may obtain a copy of the License at
-  http://www.mozilla.org/MPL/
+ This library is free software; you can redistribute it and/or modify
+ it under the terms of either:
 
-  Software distributed under the License is distributed on an "AS IS"
-  basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See
-  the License for the specific language governing rights and
-  limitations under the License.
+    The LGPL as published by the Free Software Foundation, version
+    2.1, available at: http://www.gnu.org/licenses/lgpl-2.1.html
+
+ Or:
+
+    The Mozilla Public License Version 2.0. You may obtain a copy of
+    the License at http://www.mozilla.org/MPL/
 
 ======================================================================*/
 
@@ -56,6 +57,9 @@ int main()
     for (i = 0; i < timezones->num_elements; i++) {
         zone = (icaltimezone *)icalarray_element_at(timezones, i);
         zone_location = (char *)icaltimezone_get_location(zone);
+        zonedef_printed = 0;
+        if (!zone_location)
+            continue;
 
         /*
          * select this location for glibc: needs support for TZ=<location>
@@ -66,7 +70,7 @@ int main()
 #else
         new_tz[0] = '\0';
         strncat(new_tz, "TZ=", 255);
-        strncat(new_tz, zone_location, 255);
+        strncat(new_tz, zone_location, 255 - strlen(new_tz));
         putenv(new_tz);
 #endif
         tzset();
@@ -106,7 +110,9 @@ int main()
             if (verbose || curr_failed != failed) {
                 struct tm utc_tm;
 
-                gmtime_r(&curr_time, &utc_tm);
+                if (!gmtime_r(&curr_time, &utc_tm))
+                    memset(&utc_tm, 0, sizeof(utc_tm));
+
                 printf(
                     "%s: day %03d: %s: %04d-%02d-%02d %02d:%02d:%02d UTC = "
                     "libc %04d-%02d-%02d %02d:%02d:%02d dst %d",
@@ -131,7 +137,7 @@ int main()
                 printf("\n");
                 failed = curr_failed;
 
-                if (!zonedef_printed) {
+                if (failed && !zonedef_printed) {
                     icalcomponent *comp = icaltimezone_get_component(zone);
 
                     if (comp) {
@@ -153,14 +159,8 @@ int main()
         percent_failed = total_failed * 100 / (total_failed + total_okay);
         printf(" *** Summary: %lu zones tested, %u days failed, %u okay => %u%% failed ***\n",
                (unsigned long)timezones->num_elements, total_failed, total_okay, percent_failed);
-
-        if (!icaltzutil_get_exact_vtimezones_support()) {
-            if (!percent_failed) {
-                ret = 0;
-                printf(" *** Expect some small error rate with inter-operable vtimezones *** \n");
-            }
-       }
     }
 
+    icaltimezone_free_builtin_timezones();
     return ret;
 }
