--- core/Services/Calendar/EventStore.vala.orig	2020-10-08 20:26:30 UTC
+++ core/Services/Calendar/EventStore.vala
@@ -298,19 +298,10 @@ public class Calendar.EventStore : Object {
      */
     private GLib.DateWeekday get_week_start () {
         // Set the "baseline" for start of week: Sunday or Monday?
-        // HACK Dealing with NLTime is hacky and potentially prone to breaking.
-        // This to_string call produces a string pointer whose address is the
-        // number we want, so we convert the pointer address to a uint to get
-        // the data. Since the pointer address is actually data, using it as a
-        // pointer will segfault.
-        uint week_day1 = (uint) Posix.NLTime.WEEK_1STDAY.to_string ();
-        var week_1stday = 0; // Default to 0 if unrecognized data
-        if (week_day1 == 19971130) { // Sunday
+        string locale = GLib.Intl.setlocale(ALL, null);
+        var week_1stday = 1; // Default to Monday
+        if (locale.contains("CA") || locale.contains("MX") || locale.contains("US")) {
             week_1stday = 0;
-        } else if (week_day1 == 19971201) { // Monday
-            week_1stday = 1;
-        } else {
-            warning ("Unknown value of _NL_TIME_WEEK_1STDAY: %u", week_day1);
         }
         /* The offset between GLib and local POSIX numbering.
          * If week_1stday is Monday, data is correct for GLib: Monday=1 through Sunday=7,
@@ -319,12 +310,7 @@ public class Calendar.EventStore : Object {
          * subtracted by 1, then Sunday has to be handled separately to wrap to 7. */
         var glib_offset = week_1stday - 1;
 
-        // Get the start of week
-        // HACK This line produces a string of 3 bytes. It takes the raw value
-        // of the first one and uses that as the value of week_start.
-        int week_start_posix = Posix.NLTime.FIRST_WEEKDAY.to_string ().data[0];
-
-        var week_start = week_start_posix + glib_offset;
+        var week_start = glib_offset;
         if (week_start == 0) { // Sunday special case
             week_start = 7;
         }
