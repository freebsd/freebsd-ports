--- dates.c.orig	2020-10-18 03:01:26 UTC
+++ dates.c
@@ -28,7 +28,7 @@
  */
 
 #include <sys/cdefs.h>
-__FBSDID("$FreeBSD$");
+__FBSDID("$FreeBSD: head/usr.bin/calendar/dates.c 367173 2020-10-30 15:43:52Z se $");
 
 #include <stdio.h>
 #include <stdlib.h>
@@ -64,6 +64,7 @@ struct cal_day {
 	struct cal_month *month;	/* points back */
 	struct cal_year	*year;		/* points back */
 	struct event *events;
+	struct event *lastevent;
 };
 
 int debug_remember = 0;
@@ -446,8 +447,13 @@ void
 addtodate(struct event *e, int year, int month, int day)
 {
 	struct cal_day *d;
+	struct event *ee;
 
 	d = find_day(year, month, day);
-	e->next = d->events;
-	d->events = e;
+	ee = d->lastevent;
+	if (ee != NULL)
+		ee->next = e;
+	else
+		d->events = e;
+	d->lastevent = e;
 }
