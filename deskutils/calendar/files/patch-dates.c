--- dates.c.orig	2020-10-18 03:01:26 UTC
+++ dates.c
@@ -64,6 +64,7 @@ struct cal_day {
 	struct cal_month *month;	/* points back */
 	struct cal_year	*year;		/* points back */
 	struct event *events;
+	struct event *lastevent;
 };
 
 int debug_remember = 0;
@@ -443,11 +444,16 @@ find_day(int yy, int mm, int dd)
 }
 
 void
-addtodate(struct event *e, int year, int month, int day)
+addtodate(struct event *e)
 {
 	struct cal_day *d;
+	struct event *ee;
 
-	d = find_day(year, month, day);
-	e->next = d->events;
-	d->events = e;
+	d = find_day(e->year, e->month, e->day);
+	ee = d->lastevent;
+	if (ee != NULL)
+		ee->next = e;
+	else
+		d->events = e;
+	d->lastevent = e;
 }
