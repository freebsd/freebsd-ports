--- protocol/liblivejournal/livejournal/sync.c.old	Fri Jun 18 14:57:51 2004
+++ protocol/liblivejournal/livejournal/sync.c	Fri Jun 18 14:58:20 2004
@@ -33,8 +33,10 @@
 static int
 entry_date_compare_func(const void *a, const void *b) {
 	/* struct tm* cast needed to un-constify the times passed to mktime. */
-	const LJEntry *entrya = a; time_t timea = mktime((struct tm*)&entrya->time);
-	const LJEntry *entryb = b; time_t timeb = mktime((struct tm*)&entryb->time);
+	const LJEntry *entrya = *(LJEntry **)a;
+	const LJEntry *entryb = *(LJEntry **)b;
+	time_t timea = mktime((struct tm*)&entrya->time);
+	time_t timeb = mktime((struct tm*)&entryb->time);
 	/* mktime actually converts the times to local time, which isn't
 	 * quite correct, but since we're comparing times directly like this
 	 * it should still sort the same way and timegm is potentially slower. */
