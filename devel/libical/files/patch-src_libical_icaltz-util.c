--- src/libical/icaltz-util.c.orig	2018-03-09 22:23:47 UTC
+++ src/libical/icaltz-util.c
@@ -4,20 +4,18 @@
  *
  * Copyright 2007, Novell, Inc.
  *
- * This program is free software; you can redistribute it and/or
- * modify it under the terms of version 2 of the GNU Lesser General Public
- * License as published by the Free Software Foundation.
+ * This library is free software; you can redistribute it and/or modify
+ * it under the terms of either:
  *
- * This program is distributed in the hope that it will be useful,
- * but WITHOUT ANY WARRANTY; without even the implied warranty of
- * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
- * GNU Lesser General Public License for more details.
+ *   The LGPL as published by the Free Software Foundation, version
+ *   2.1, available at: http://www.gnu.org/licenses/lgpl-2.1.html
  *
- * * You should have received a copy of the GNU Lesser General Public
- * License along with this library; if not, write to the
- * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
- * Boston, MA 02110-1301, USA.
+ * Or:
+ *
+ *   The Mozilla Public License Version 2.0. You may obtain a copy of
+ *   the License at http://www.mozilla.org/MPL/
  */
+//krazy:excludeall=cpp
 
 #ifdef HAVE_CONFIG_H
 #include <config.h>
@@ -93,9 +91,9 @@ typedef struct
     char charcnt[4];
 } tzinfo;
 
-static char *zdir = NULL;
+static const char *zdir = NULL;
 
-static char *search_paths[] = {
+static const char *search_paths[] = {
     "/usr/share/zoneinfo",
     "/usr/lib/zoneinfo",
     "/etc/zoneinfo",
@@ -144,6 +142,7 @@ static int decode(const void *ptr)
         const unsigned char *p = ptr;
         int result = *p & (1 << (CHAR_BIT - 1)) ? ~0 : 0;
 
+        /* cppcheck-suppress shiftNegative */
         result = (result << 8) | *p++;
         result = (result << 8) | *p++;
         result = (result << 8) | *p++;
@@ -153,9 +152,9 @@ static int decode(const void *ptr)
     }
 }
 
-static char *zname_from_stridx(char *str, long idx)
+static char *zname_from_stridx(char *str, size_t idx)
 {
-    long i;
+    size_t i;
     size_t size;
     char *ret;
 
@@ -164,7 +163,7 @@ static char *zname_from_stridx(char *str
         i++;
     }
 
-    size = (size_t)(i - idx);
+    size = i - idx;
     str += idx;
     ret = (char *)malloc(size + 1);
     ret = strncpy(ret, str, size);
@@ -197,45 +196,6 @@ const char *icaltzutil_get_zone_director
     return zdir;
 }
 
-static void find_transidx(time_t *transitions, ttinfo *types,
-                          int *trans_idx, long int num_trans,
-                          int *stdidx, int *dstidx)
-{
-    time_t now, year_start;
-    int i, found = 0;
-    struct icaltimetype itime;
-
-    now = time(NULL);
-    itime = icaltime_from_timet(now, 0);
-    itime.month = itime.day = 1;
-    itime.hour = itime.minute = itime.second = 0;
-    year_start = icaltime_as_timet(itime);
-
-    /* Set this by default */
-    *stdidx = (num_trans - 1);
-
-    for (i = (num_trans - 1); i >= 0; --i) {
-        if (year_start < transitions[i]) {
-          int idx;
-          found = 1;
-          idx = trans_idx[i];
-          (types[idx].isdst) ? (*dstidx = i) : (*stdidx = i);
-        }
-    }
-
-    /* If the transition found is the last among the list, prepare to use the last two transtions.
-     * Using this will most likely throw the DTSTART of the resulting component off by 1 or 2 days
-     * but it would set right by the adjustment made.
-     * NOTE: We need to use the last two transitions only because there is no data for the future
-     * transitions.
-     */
-    if (found && (*dstidx == -1)) {
-        *dstidx = ((*stdidx) - 1);
-    }
-
-    return;
-}
-
 static int calculate_pos(icaltimetype icaltime)
 {
    static int r_pos[] = {1, 2, 3, -2, -1};
@@ -251,22 +211,6 @@ static int calculate_pos(icaltimetype ic
    return r_pos[pos];
 }
 
-#if defined(USE_INTEROPERABLE_VTIMEZONES)
-static int _s_use_exact_timezones = 0;
-#else
-static int _s_use_exact_timezones = 1;
-#endif
-
-void icaltzutil_set_exact_vtimezones_support(int on)
-{
-    _s_use_exact_timezones = (on != 0);
-}
-
-int icaltzutil_get_exact_vtimezones_support(void)
-{
-    return _s_use_exact_timezones;
-}
-
 static void adjust_dtstart_day_to_rrule(icalcomponent *comp, struct icalrecurrencetype rule)
 {
     time_t now, year_start;
@@ -274,13 +218,13 @@ static void adjust_dtstart_day_to_rrule(
     icalrecur_iterator *iter;
 
     now = time(NULL);
-    itime = icaltime_from_timet(now, 0);
+    itime = icaltime_from_timet_with_zone(now, 0, NULL);
     itime.month = itime.day = 1;
     itime.hour = itime.minute = itime.second = 0;
     year_start = icaltime_as_timet(itime);
 
     comp_start = icalcomponent_get_dtstart(comp);
-    start = icaltime_from_timet(year_start, 0);
+    start = icaltime_from_timet_with_zone(year_start, 0, NULL);
 
     iter = icalrecur_iterator_new(rule, start);
     iter_start = icalrecur_iterator_next(iter);
@@ -298,9 +242,8 @@ icalcomponent *icaltzutil_fetch_timezone
     size_t i, num_trans, num_chars, num_leaps, num_isstd, num_isgmt;
     size_t num_types = 0;
     size_t size;
-    time_t trans;
-    int dstidx = -1, stdidx = -1, pos, sign, zidx, zp_idx;
-    icalcomponent *std_comp = NULL;
+    int pos, sign;
+    time_t now = time(NULL);
 
     const char *zonedir;
     FILE *f = NULL;
@@ -313,12 +256,22 @@ icalcomponent *icaltzutil_fetch_timezone
     leap *leaps = NULL;
     char *tzid = NULL;
 
-    time_t start, end;
     int idx, prev_idx;
-    icalcomponent *tz_comp = NULL, *comp = NULL, *dst_comp;
+    icalcomponent *tz_comp = NULL, *comp = NULL;
     icalproperty *icalprop;
-    icaltimetype dtstart, icaltime;
-    struct icalrecurrencetype ical_recur;
+    icaltimetype icaltime;
+    struct icalrecurrencetype standard_recur;
+    struct icalrecurrencetype daylight_recur;
+    icaltimetype prev_standard_time = icaltime_null_time();
+    icaltimetype prev_daylight_time = icaltime_null_time();
+    icaltimetype prev_prev_standard_time;
+    icaltimetype prev_prev_daylight_time;
+    long prev_standard_gmtoff;
+    long prev_daylight_gmtoff;
+    icalcomponent *cur_standard_comp = NULL;
+    icalcomponent *cur_daylight_comp = NULL;
+    icalproperty *cur_standard_rrule_property;
+    icalproperty *cur_daylight_rrule_property;
 
     if (icaltimezone_get_builtin_tzdata()) {
         goto error;
@@ -448,15 +401,8 @@ icalcomponent *icaltzutil_fetch_timezone
     /* Read all the contents now */
 
     for (i = 0; i < num_types; i++) {
-        types[i].zname = zname_from_stridx(znames, (long)types[i].abbr);
-    }
-
-    if (!_s_use_exact_timezones) {
-        if (num_trans != 0) {
-            find_transidx(transitions, types, trans_idx, (long int)num_trans, &stdidx, &dstidx);
-        } else {
-            stdidx = 0;
-        }
+        /* coverity[tainted_data] */
+        types[i].zname = zname_from_stridx(znames, types[i].abbr);
     }
 
     tz_comp = icalcomponent_new(ICAL_VTIMEZONE_COMPONENT);
@@ -476,140 +422,202 @@ icalcomponent *icaltzutil_fetch_timezone
     icalproperty_set_x_name(icalprop, "X-LIC-LOCATION");
     icalcomponent_add_property(tz_comp, icalprop);
 
-    if (!_s_use_exact_timezones) {
-        if (stdidx != -1) {
-            if (num_trans != 0) {
-                zidx = trans_idx[stdidx];
+    prev_idx = 0;
+    if (num_trans == 0) {
+        prev_idx = idx = 0;
+    } else {
+        idx = trans_idx[0];
+    }
+
+    for (i = 1; i < num_trans; i++) {
+        int by_day;
+        int is_new_comp = 0;
+        time_t start;
+        struct icalrecurrencetype *recur;
+
+        prev_idx = idx;
+        idx = trans_idx[i];
+        start = transitions[i] + types[prev_idx].gmtoff;
+
+        icaltime = icaltime_from_timet_with_zone(start, 0, NULL);
+        pos = calculate_pos(icaltime);
+        pos < 0 ? (sign = -1): (sign = 1);
+        by_day = sign * ((abs(pos) * 8) + icaltime_day_of_week(icaltime));
+
+        // Figure out if the rule has changed since the previous year
+        // If it has, update the recurrence rule of the current component and create a new component
+        // If it the current component was only valid for one year then remove the recurrence rule
+        if (types[idx].isdst) {
+            if (cur_daylight_comp) {
+                // Check if the pattern for daylight has changed
+                // If it has, create a new component and update UNTIL of previous component's RRULE
+                if (daylight_recur.by_month[0] != icaltime.month ||
+                        daylight_recur.by_day[0] != by_day ||
+                        types[prev_idx].gmtoff != prev_daylight_gmtoff) {
+                    // Set UNTIL of the previous component's recurrence
+                    icaltime_adjust(&prev_daylight_time, 0, 0, 0, -types[prev_idx].gmtoff);
+                    prev_daylight_time.is_utc = 1;
+
+                    daylight_recur.until = prev_daylight_time;
+                    icalproperty_set_rrule(cur_daylight_rrule_property, daylight_recur);
+
+                    cur_daylight_comp = icalcomponent_new(ICAL_XDAYLIGHT_COMPONENT);
+                    is_new_comp = 1;
+                }
             } else {
-                zidx = 0;
+                cur_daylight_comp = icalcomponent_new(ICAL_XDAYLIGHT_COMPONENT);
+                is_new_comp = 1;
             }
 
-            std_comp = icalcomponent_new(ICAL_XSTANDARD_COMPONENT);
-            icalprop = icalproperty_new_tzname(types[zidx].zname);
-            icalcomponent_add_property(std_comp, icalprop);
+            comp = cur_daylight_comp;
+            recur = &daylight_recur;
 
-            if (dstidx != -1) {
-                zp_idx = trans_idx[stdidx-1];
+            if (icaltime_is_null_time(prev_daylight_time)) {
+                prev_prev_daylight_time = icaltime;
             } else {
-                zp_idx = zidx;
+                prev_prev_daylight_time = prev_daylight_time;
             }
-            /* DTSTART localtime uses TZOFFSETFROM UTC offset */
-            if (num_trans != 0) {
-                trans = transitions[stdidx] + types[zp_idx].gmtoff;
+
+            prev_daylight_time = icaltime;
+            prev_daylight_gmtoff = types[prev_idx].gmtoff;
+        } else {
+            if (cur_standard_comp) {
+                // Check if the pattern for standard has changed
+                // If it has, create a new component and update UNTIL
+                // of the previous component's RRULE
+                if (standard_recur.by_month[0] != icaltime.month ||
+                        standard_recur.by_day[0] != by_day ||
+                        types[prev_idx].gmtoff != prev_standard_gmtoff) {
+                    icaltime_adjust(&prev_standard_time, 0, 0, 0, -types[prev_idx].gmtoff);
+                    prev_standard_time.is_utc = 1;
+
+                    standard_recur.until = prev_standard_time;
+                    icalproperty_set_rrule(cur_standard_rrule_property, standard_recur);
+
+                    cur_standard_comp = icalcomponent_new(ICAL_XSTANDARD_COMPONENT);
+                    is_new_comp = 1;
+
+                    // Are we transitioning on the daylight date?
+                    // If so, that means the time zone is switching off of DST
+                    // We need to set UNTIL for the daylight component
+                    if (cur_daylight_comp && daylight_recur.by_month[0] == icaltime.month &&
+                            daylight_recur.by_day[0] == by_day) {
+                        icaltime_adjust(&prev_daylight_time, 0, 0, 0, -types[prev_idx].gmtoff);
+                        prev_daylight_time.is_utc = 1;
+
+                        daylight_recur.until = prev_daylight_time;
+                        icalproperty_set_rrule(cur_daylight_rrule_property, daylight_recur);
+                    }
+                }
             } else {
-                trans = (time_t)types[zp_idx].gmtoff;
+                cur_standard_comp = icalcomponent_new(ICAL_XSTANDARD_COMPONENT);
+                is_new_comp = 1;
             }
-            icaltime = icaltime_from_timet(trans, 0);
-            dtstart = icaltime;
-            dtstart.year = 1970;
-            dtstart.minute = dtstart.second = 0;
-            icalprop = icalproperty_new_dtstart(dtstart);
-            icalcomponent_add_property(std_comp, icalprop);
 
-            /* If DST changes are present use RRULE */
-            if (dstidx != -1) {
-                icalrecurrencetype_clear(&ical_recur);
-                ical_recur.freq = ICAL_YEARLY_RECURRENCE;
-                ical_recur.by_month[0] = icaltime.month;
-                pos = calculate_pos(icaltime);
-                pos < 0 ? (sign = -1): (sign = 1);
-                ical_recur.by_day[0] = sign * ((abs(pos) * 8) + icaltime_day_of_week(icaltime));
-                icalprop = icalproperty_new_rrule(ical_recur);
-                icalcomponent_add_property(std_comp, icalprop);
+            comp = cur_standard_comp;
+            recur = &standard_recur;
 
-                adjust_dtstart_day_to_rrule(std_comp, ical_recur);
+            if (icaltime_is_null_time(prev_standard_time)) {
+                prev_prev_standard_time = icaltime;
+            } else {
+                prev_prev_standard_time = prev_standard_time;
             }
-            icalprop = icalproperty_new_tzoffsetfrom(types[zp_idx].gmtoff);
-            icalcomponent_add_property(std_comp, icalprop);
-            icalprop = icalproperty_new_tzoffsetto(types[zidx].gmtoff);
-            icalcomponent_add_property(std_comp, icalprop);
-            icalcomponent_add_component(tz_comp, std_comp);
-        } else {
-            icalerror_set_errno(ICAL_MALFORMEDDATA_ERROR);
+
+            prev_standard_time = icaltime;
+            prev_standard_gmtoff = types[prev_idx].gmtoff;
         }
 
-        if (dstidx != -1) {
-            zidx = trans_idx[dstidx];
-            zp_idx = trans_idx[dstidx-1];
-            dst_comp = icalcomponent_new(ICAL_XDAYLIGHT_COMPONENT);
-            icalprop = icalproperty_new_tzname(types[zidx].zname);
-            icalcomponent_add_property(dst_comp, icalprop);
+        if (is_new_comp) {
+            icalprop = icalproperty_new_tzname(types[idx].zname);
+            icalcomponent_add_property(comp, icalprop);
+            icalprop = icalproperty_new_dtstart(icaltime);
+            icalcomponent_add_property(comp, icalprop);
+            icalprop = icalproperty_new_tzoffsetfrom(types[prev_idx].gmtoff);
+            icalcomponent_add_property(comp, icalprop);
+            icalprop = icalproperty_new_tzoffsetto(types[idx].gmtoff);
+            icalcomponent_add_property(comp, icalprop);
 
-            /* DTSTART localtime uses TZOFFSETFROM UTC offset */
-            if (num_trans != 0) {
-                trans = transitions[dstidx] + types[zp_idx].gmtoff;
+            // Determine the recurrence rule for the current set of changes
+            icalrecurrencetype_clear(recur);
+            recur->freq = ICAL_YEARLY_RECURRENCE;
+            recur->by_month[0] = icaltime.month;
+            recur->by_day[0] = by_day;
+            icalprop = icalproperty_new_rrule(*recur);
+            icalcomponent_add_property(comp, icalprop);
+
+            if (types[idx].isdst) {
+                cur_daylight_rrule_property = icalprop;
             } else {
-                trans = (time_t)types[zp_idx].gmtoff;
+                cur_standard_rrule_property = icalprop;
             }
 
-            icaltime = icaltime_from_timet(trans, 0);
-            dtstart = icaltime;
-            dtstart.year = 1970;
-            dtstart.minute = dtstart.second = 0;
-            icalprop = icalproperty_new_dtstart(dtstart);
-            icalcomponent_add_property(dst_comp, icalprop);
+            adjust_dtstart_day_to_rrule(comp, *recur);
 
-            icalrecurrencetype_clear(&ical_recur);
-            ical_recur.freq = ICAL_YEARLY_RECURRENCE;
-            ical_recur.by_month[0] = icaltime.month;
-            pos = calculate_pos(icaltime);
-            pos < 0 ? (sign = -1): (sign = 1);
-            ical_recur.by_day[0] = sign * ((abs(pos) * 8) + icaltime_day_of_week(icaltime));
-            icalprop = icalproperty_new_rrule(ical_recur);
-            icalcomponent_add_property(dst_comp, icalprop);
+            icalcomponent_add_component(tz_comp, comp);
+        }
+    }
 
-            adjust_dtstart_day_to_rrule(dst_comp, ical_recur);
+    // Check if the last daylight or standard date was before now
+    // If so, set the UNTIL date to the second-to-last transition date
+    // and then insert a new component to indicate the time zone doesn't transition anymore
+    if (cur_daylight_comp && icaltime_as_timet(prev_daylight_time) < now) {
+        icaltime_adjust(&prev_prev_daylight_time, 0, 0, 0, -prev_daylight_gmtoff);
+        prev_prev_daylight_time.is_utc = 1;
 
-            icalprop = icalproperty_new_tzoffsetfrom(types[zp_idx].gmtoff);
-            icalcomponent_add_property(dst_comp, icalprop);
+        daylight_recur.until = prev_prev_daylight_time;
+        icalproperty_set_rrule(cur_daylight_rrule_property, daylight_recur);
 
-            icalprop = icalproperty_new_tzoffsetto(types[zidx].gmtoff);
-            icalcomponent_add_property(dst_comp, icalprop);
+        comp = icalcomponent_new(ICAL_XDAYLIGHT_COMPONENT);
+        icalprop = icalproperty_new_tzname(types[idx].zname);
+        icalcomponent_add_property(comp, icalprop);
+        icalprop = icalproperty_new_dtstart(prev_daylight_time);
+        icalcomponent_add_property(comp, icalprop);
+        icalprop = icalproperty_new_tzoffsetfrom(types[prev_idx].gmtoff);
+        icalcomponent_add_property(comp, icalprop);
+        icalprop = icalproperty_new_tzoffsetto(types[idx].gmtoff);
+        icalcomponent_add_property(comp, icalprop);
+        icalcomponent_add_component(tz_comp, comp);
+    }
 
-            icalcomponent_add_component(tz_comp, dst_comp);
-        }
-    } else { /*exact vtimezones*/
-        prev_idx = 0;
-        if (num_trans == 0) {
-            prev_idx = idx = 0;
+    if (cur_standard_comp && icaltime_as_timet(prev_standard_time) < now) {
+        icaltime_adjust(&prev_prev_standard_time, 0, 0, 0, -prev_standard_gmtoff);
+        prev_prev_standard_time.is_utc = 1;
+
+        standard_recur.until = prev_prev_standard_time;
+        icalproperty_set_rrule(cur_standard_rrule_property, standard_recur);
+
+        comp = icalcomponent_new(ICAL_XSTANDARD_COMPONENT);
+        icalprop = icalproperty_new_tzname(types[idx].zname);
+        icalcomponent_add_property(comp, icalprop);
+        icalprop = icalproperty_new_dtstart(prev_standard_time);
+        icalcomponent_add_property(comp, icalprop);
+        icalprop = icalproperty_new_tzoffsetfrom(types[prev_idx].gmtoff);
+        icalcomponent_add_property(comp, icalprop);
+        icalprop = icalproperty_new_tzoffsetto(types[idx].gmtoff);
+        icalcomponent_add_property(comp, icalprop);
+        icalcomponent_add_component(tz_comp, comp);
+    }
+
+    if (num_trans <= 1) {
+        time_t start;
+
+        if (num_trans == 1) {
+            start = transitions[0] + types[prev_idx].gmtoff;
         } else {
-            idx = trans_idx[0];
+            start = 0;
         }
-        start = 0;
-        for (i = 1; i < num_trans; i++, start = end) {
-            prev_idx = idx;
-            idx = trans_idx[i];
-            end = transitions[i] + types[prev_idx].gmtoff;
-            /* don't bother starting until the epoch */
-            if (0 > end)
-                continue;
 
-            if (types[prev_idx].isdst) {
-                comp = icalcomponent_new(ICAL_XDAYLIGHT_COMPONENT);
-            } else {
-                comp = icalcomponent_new(ICAL_XSTANDARD_COMPONENT);
-            }
-            icalprop = icalproperty_new_tzname(types[prev_idx].zname);
-            icalcomponent_add_property(comp, icalprop);
-            dtstart = icaltime_from_timet(start, 0);
-            icalprop = icalproperty_new_dtstart(dtstart);
-            icalcomponent_add_property(comp, icalprop);
-            icalprop = icalproperty_new_tzoffsetfrom(types[idx].gmtoff);
-            icalcomponent_add_property(comp, icalprop);
-            icalprop = icalproperty_new_tzoffsetto(types[prev_idx].gmtoff);
-            icalcomponent_add_property(comp, icalprop);
-            icalcomponent_add_component(tz_comp, comp);
-        }
-        /* finally, add a last zone with no end date */
+        // This time zone doesn't transition, insert a single VTIMEZONE component
         if (types[idx].isdst) {
             comp = icalcomponent_new(ICAL_XDAYLIGHT_COMPONENT);
         } else {
             comp = icalcomponent_new(ICAL_XSTANDARD_COMPONENT);
         }
+
         icalprop = icalproperty_new_tzname(types[idx].zname);
         icalcomponent_add_property(comp, icalprop);
-        dtstart = icaltime_from_timet(start, 0);
-        icalprop = icalproperty_new_dtstart(dtstart);
+        icaltime = icaltime_from_timet_with_zone(start, 0, NULL);
+        icalprop = icalproperty_new_dtstart(icaltime);
         icalcomponent_add_property(comp, icalprop);
         icalprop = icalproperty_new_tzoffsetfrom(types[prev_idx].gmtoff);
         icalcomponent_add_property(comp, icalprop);
