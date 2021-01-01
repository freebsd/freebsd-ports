--- core/Services/Calendar/EventStore.vala.orig	2020-10-08 20:26:30 UTC
+++ core/Services/Calendar/EventStore.vala
@@ -303,7 +303,7 @@ public class Calendar.EventStore : Object {
         // number we want, so we convert the pointer address to a uint to get
         // the data. Since the pointer address is actually data, using it as a
         // pointer will segfault.
-        uint week_day1 = (uint) Posix.NLTime.WEEK_1STDAY.to_string ();
+        uint week_day1 = (uint) Posix.NLItem.DAY_1.to_string ();
         var week_1stday = 0; // Default to 0 if unrecognized data
         if (week_day1 == 19971130) { // Sunday
             week_1stday = 0;
@@ -322,7 +322,7 @@ public class Calendar.EventStore : Object {
         // Get the start of week
         // HACK This line produces a string of 3 bytes. It takes the raw value
         // of the first one and uses that as the value of week_start.
-        int week_start_posix = Posix.NLTime.FIRST_WEEKDAY.to_string ().data[0];
+        int week_start_posix = Posix.NLItem.DAY_1.to_string ().data[0];
 
         var week_start = week_start_posix + glib_offset;
         if (week_start == 0) { // Sunday special case
